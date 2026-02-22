#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#include <linux/nl80211.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static struct nl_sock *sock = NULL;
static int nl80211_id;
static int scan_result_handler(struct nl_msg *msg, void *arg) {
    printf("Received scan result...\n");  // Debug print

    struct nlattr *tb[NL80211_ATTR_MAX + 1];
    struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
    struct nlattr *bss[NL80211_BSS_MAX + 1];
    static struct nla_policy bss_policy[NL80211_BSS_MAX + 1] = {
        [NL80211_BSS_TSF] = { .type = NLA_U64 },
        [NL80211_BSS_FREQUENCY] = { .type = NLA_U32 },
        [NL80211_BSS_BSSID] = { },
        [NL80211_BSS_BEACON_INTERVAL] = { .type = NLA_U16 },
        [NL80211_BSS_CAPABILITY] = { .type = NLA_U16 },
        [NL80211_BSS_INFORMATION_ELEMENTS] = { },
        [NL80211_BSS_SIGNAL_MBM] = { .type = NLA_U32 },
        [NL80211_BSS_SIGNAL_UNSPEC] = { .type = NLA_U8 },
        [NL80211_BSS_STATUS] = { .type = NLA_U32 },
        [NL80211_BSS_SEEN_MS_AGO] = { .type = NLA_U32 },
        [NL80211_BSS_BEACON_IES] = { },
    };

    nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
              genlmsg_attrlen(gnlh, 0), NULL);
    
    if (!tb[NL80211_ATTR_BSS]) {
        printf("No BSS info received!\n");  // Debug print
        return NL_SKIP;
    }

    if (nla_parse_nested(bss, NL80211_BSS_MAX, tb[NL80211_ATTR_BSS], bss_policy)) {
        printf("Failed to parse BSS attributes!\n");  // Debug print
        return NL_SKIP;
    }

    // Extract and print BSS information
    if (bss[NL80211_BSS_BSSID]) {
        unsigned char *bssid = nla_data(bss[NL80211_BSS_BSSID]);
        printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",
               bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
    }

    if (bss[NL80211_BSS_FREQUENCY]) {
        printf("Frequency: %d MHz\n", nla_get_u32(bss[NL80211_BSS_FREQUENCY]));
    }

    if (bss[NL80211_BSS_SIGNAL_MBM]) {
        printf("Signal: %d dBm\n", (int8_t)(nla_get_u32(bss[NL80211_BSS_SIGNAL_MBM]) / 100));
    }

    // Add more attributes as needed (SSID, etc.)
    printf("-----\n");
    
    return NL_OK;  // Return NL_OK to continue processing other messages
}

int trigger_scan(const char *ifname) {
    struct nl_msg *msg = nlmsg_alloc();
    if (!msg) return -1;

    genlmsg_put(msg, 0, 0, nl80211_id, 0, 0, NL80211_CMD_TRIGGER_SCAN, 0);
    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, if_nametoindex(ifname));

    // Empty SSIDs = wildcard scan
    struct nl_msg *ssids = nlmsg_alloc();
    nla_put(ssids, 1, 0, "");
    nla_put_nested(msg, NL80211_ATTR_SCAN_SSIDS, ssids);

    if (nl_send_auto(sock, msg) < 0) {
        nlmsg_free(ssids);
        nlmsg_free(msg);
        return -1;
    }

    nlmsg_free(ssids);
    nlmsg_free(msg);
    return 0;

nla_put_failure:
    nlmsg_free(msg);
    return -1;
}

int get_scan_results(const char *ifname) {
    struct nl_msg *msg = nlmsg_alloc();
    if (!msg) return -1;

    genlmsg_put(msg, 0, 0, nl80211_id, 0, 0, NL80211_CMD_GET_SCAN, 0);
    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, if_nametoindex(ifname));

    nl_socket_modify_cb(sock, NL_CB_VALID, NL_CB_CUSTOM, scan_result_handler, NULL);

    if (nl_send_auto(sock, msg) < 0) {
        nlmsg_free(msg);
        return -1;
    }

    nl_recvmsgs_default(sock);
    nlmsg_free(msg);
    return 0;

nla_put_failure:
    nlmsg_free(msg);
    return -1;
}

int main() {
    const char *ifname = "wlp0s20f3";  // Set your wireless interface

    sock = nl_socket_alloc();
    if (!sock) {
        fprintf(stderr, "Failed to allocate netlink socket\n");
        return -1;
    }

    if (genl_connect(sock)) {
        fprintf(stderr, "Failed to connect to generic netlink\n");
        nl_socket_free(sock);
        return -1;
    }

    nl80211_id = genl_ctrl_resolve(sock, "nl80211");
    if (nl80211_id < 0) {
        fprintf(stderr, "nl80211 not found\n");
        nl_socket_free(sock);
        return -1;
    }

    printf("Triggering scan...\n");
    if (trigger_scan(ifname) < 0) {
        fprintf(stderr, "Failed to trigger scan\n");
        nl_socket_free(sock);
        return -1;
    }

    sleep(15); // Wait for scan to complete

    printf("Getting scan results...\n");
    if (get_scan_results(ifname) < 0) {
        printf("Failed to get scan results\n");
        nl_socket_free(sock);
        return -1;
    }

    nl_socket_free(sock);
    return 0;
}

#include <libwebsockets.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PAYLOAD 512

static int callback_client(
    struct lws *wsi,
    enum lws_callback_reasons reason,
    void *user,
    void *in,
    size_t len)
{
    switch (reason) {

        case LWS_CALLBACK_CLIENT_ESTABLISHED:
        {
            printf("Connected to server\n");

            const char *msg = "Hello from C client";

            unsigned char buffer[LWS_PRE + MAX_PAYLOAD];
            size_t msg_len = strlen(msg);

            memcpy(&buffer[LWS_PRE], msg, msg_len);
            lws_write(wsi, &buffer[LWS_PRE], msg_len, LWS_WRITE_TEXT);
            break;
        }

        case LWS_CALLBACK_CLIENT_RECEIVE:
            printf("Received: %s\n", (char *)in);
            break;

        case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
            printf("Connection error\n");
            break;

        case LWS_CALLBACK_CLOSED:
            printf("Connection closed\n");
            break;

        default:
            break;
    }

    return 0;
}

static struct lws_protocols protocols[] = {
    {
        "chat-protocol",
        callback_client,
        0,
        MAX_PAYLOAD,
    },
    { NULL, NULL, 0, 0 }
};

int main() {

    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));

    info.port = CONTEXT_PORT_NO_LISTEN;
    info.protocols = protocols;

    struct lws_context *context = lws_create_context(&info);
    if (!context) {
        printf("Failed to create context\n");
        return -1;
    }

    struct lws_client_connect_info ccinfo = {0};
    ccinfo.context = context;
    ccinfo.address = "localhost";
    ccinfo.port = 9000;
    ccinfo.path = "/";
    ccinfo.host = lws_canonical_hostname(context);
    ccinfo.origin = "origin";
    ccinfo.protocol = "chat-protocol";

    if (!lws_client_connect_via_info(&ccinfo)) {
        printf("Client connection failed\n");
        return -1;
    }

    while (1) {
        lws_service(context, 100);
    }

    lws_context_destroy(context);
    return 0;
}

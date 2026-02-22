#include <libwebsockets.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PAYLOAD 512

typedef struct {
    struct lws *wsi;
} client_t;

static int callback_chat(
    struct lws *wsi,
    enum lws_callback_reasons reason,
    void *user,
    void *in,
    size_t len)
{
    switch (reason) {

        case LWS_CALLBACK_ESTABLISHED:
            printf("Client connected\n");
            break;

        case LWS_CALLBACK_RECEIVE:
        {
            printf("Received: %s\n", (char *)in);

            unsigned char buffer[LWS_PRE + MAX_PAYLOAD];
            memcpy(&buffer[LWS_PRE], in, len);

            lws_write(wsi, &buffer[LWS_PRE], len, LWS_WRITE_TEXT);
            break;
        }

        case LWS_CALLBACK_CLOSED:
            printf("Client disconnected\n");
            break;

        default:
            break;
    }

    return 0;
}

static struct lws_protocols protocols[] = {
    {
        "chat-protocol",
        callback_chat,
        0,
        MAX_PAYLOAD,
    },
    { NULL, NULL, 0, 0 }
};

int main() {

    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));

    info.port = 9000;
    info.protocols = protocols;

    struct lws_context *context = lws_create_context(&info);
    if (!context) {
        printf("Failed to create context\n");
        return -1;
    }

    printf("WebSocket server started on port 9000\n");

    while (1) {
        lws_service(context, 1000);
    }

    lws_context_destroy(context);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX 8

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear  = -1;   // no items yet
}

bool is_empty(const Queue *q) {
    return q->front > q->rear;
}

bool is_full(const Queue *q) {
    return q->rear == MAX - 1;
}

int enqueue(Queue *q, int val) {
    if (is_full(q)) return -1;   // overflow
    q->data[++(q->rear)] = val;
    return 0;
}

int dequeue(Queue *q, int *out) {
    if (is_empty(q)) return -1;  // underflow
    *out = q->data[q->front++];
    return 0;
}

void print(const Queue *q) {
    if (is_empty(q)) {
        printf("[empty]\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print(&q);

    int val;
    dequeue(&q, &val); printf("Dequeue: %d\n", val);
    dequeue(&q, &val); printf("Dequeue: %d\n", val);

    print(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);

    print(&q);

    return 0;
}

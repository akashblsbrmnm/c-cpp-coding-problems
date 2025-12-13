#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 8

typedef struct
{
    int data[STACK_CAPACITY];
    int top;
} Stack;

void stack_init(Stack *s)
{
    s->top = -1;
}

bool is_empty(const Stack *s)
{
    return s->top == -1;
}

bool is_full(const Stack *s)
{
    return s->top >= STACK_CAPACITY - 1;
}

int stack_size(const Stack *s)
{
    return s->top + 1;
}

int push(Stack *s, int item)
{
    if (is_full(s))
    {
        printf("Stack Overflow\n");
        return -1;
    }
    s->data[++(s->top)] = item;
    return 0;
}

int pop(Stack *s, int *out) {
    if (is_empty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    *out = s->data[(s->top)--];
    return 0;
}

int peek(const Stack *s, int *out)
{
    if (is_empty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    *out = s->data[s->top];
    return 0;
}

void clear(Stack *s)
{
    s->top = -1;
}

void display(const Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack : ");
    for (int i = s->top; i >= 0; --i)
    {
        printf("%d", s->data[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

int main(void)
{
    Stack st;
    stack_init(&st);
    int item;

    printf("Initial: ");
    display(&st);

    printf("\nPushing 1..5 onto stack\n");
    for (int i = 1; i <= 5; ++i) {
        if (push(&st, i) == 0)
        {
            printf("push(%d) ok\n", i);
        }
    }
    display(&st);
    printf("Size = %d\n", stack_size(&st));

    if (peek(&st, &item) == 0) printf("peek top = %d\n", item);

    printf("\nPopping two elements\n");
    for (int i = 0; i < 2; ++i) {
        if (pop(&st, &item) == 0) printf("pop() -> %d\n", item);
        else printf("pop() failed: underflow\n");
    }
    display(&st);

    printf("\nFilling stack to capacity to demonstrate overflow\n");
    while (push(&st, 100) == 0) { /* push until full */ }
    display(&st);
    if (push(&st, 999) != 0) printf("push(999) failed: overflow (as expected)\n");

    printf("\nClearing stack\n");
    clear(&st);
    display(&st);

    return 0;
}


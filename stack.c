#include <stdio.h>
#include <string.h>

typedef int bool_t;
#define true 1
#define false 0

#define STACK_MAXSIZE 1024

typedef struct stack stack_t;

typedef struct stack
{
    bool_t (*push)(stack_t *stack, int i);
    bool_t (*pop)(stack_t *stack, int *i);
    void (*display)(stack_t *stack);
    int arr[STACK_MAXSIZE];
    int top;
} stack_t;

bool_t stack_push(stack_t *stack, int c)
{
    stack->arr[++stack->top] = c;
    return true;
}

bool_t stack_pop(stack_t *stack, int *c)
{
    if (stack->top ==-1) {
        return false;
    } else {
        *c = stack->arr[stack->top--];
        return true;
    }
}

void stack_display(stack_t *stack)
{
    int i;
    for(i = stack->top; i >= 0; i--)
        printf("%d\n", stack->arr[i]); 
}

void init_stack(stack_t *s)
{
    s->top       = -1; 
    s->push     = stack_push;
    s->pop      = stack_pop;
    s->display  = stack_display;
    memset(s->arr, 0, sizeof(s->arr));
}

int main(void)
{
    int i;
    stack_t my_stack; 
    stack_t *stack = &my_stack;

    init_stack(stack);

    stack->display(stack);
    for (i = 0; i < 100; i++)
        stack->push(stack, i);
    stack->display(stack);
}

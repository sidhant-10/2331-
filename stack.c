#include "stack.h"
#include<stdio.h>
void push(Stack *stack, char item) {
    if (is_full(stack))
        printf("Overflow\n");
    else {
        stack->top++;
        stack->data[stack->top] = item;
    }
}

void init(Stack *stack) {
    stack->top = -1; // Initialize top to -1 for an empty stack
}

int is_empty(Stack *stack) {
    return stack->top == -1; // Return 1 if stack is empty, 0 otherwise
}

int is_full(Stack *stack) {
    return stack->top == STACK_SIZE - 1; // Return 1 if stack is full, 0 otherwise
}

char pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Underflow\n");
        return -1; // Return a special value to indicate underflow
    } else {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}
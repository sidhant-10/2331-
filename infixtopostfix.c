#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "infixtopostfix.h"

// Function to determine the precedence of operators
int precedence(char operato) {
    if (operato == '+' || operato == '-') {
        return 1;
    } else if (operato == '*' || operato == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    init(&stack);
    int len = strlen(infix);
    int j = 0;

    for (int i = 0; i < len; i++) {
        char token = infix[i];

        if (token >= '0' && token <= '9') {
            postfix[j++] = token; // If it's a digit, add it to the output
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '('
        } else {
            // It's an operator
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    // Pop any remaining operators from the stack
    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

   
}
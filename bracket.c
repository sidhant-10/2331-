#include <stdio.h>
#include "stack.h"
#include "bracket.h"

int areBracketsBalanced(const char* expression) {
    Stack stack;
    init(&stack);

    for (int i = 0; expression[i]; i++) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (is_empty(&stack)) {
                return 0; // Unmatched closing bracket
            }

            char topChar = pop(&stack);

            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == '}' && topChar != '{') ||
                (currentChar == ']' && topChar != '[')) {
                return 0; // Mismatched opening and closing brackets
            }
        }
    }

    return is_empty(&stack); // If the stack is empty, all brackets are balanced.
}

#include "stack.h"
#include "postfix.h"
#include <stdio.h>

int is_operator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  
    }  
    return 0;  
}  
int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
    Stack stack;

    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(&stack,num);  
        }  
        else if (is_operator(symbol)) {  
            operand2 = pop(&stack);  
            operand1 = pop(&stack);  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(&stack,result);  
        }  
i++;  
        symbol = expression[i];  
    }  
    result = pop(&stack);  
    return result;  
}  
  
// int main() {  
//     char expression[] = "5 6 7 + * 8 -";  
//     int result = evaluate(expression);  
// printf("Result= %d\n", result);  
// return 0;  
// }  
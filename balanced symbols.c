#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        return -1;  
    } else {
        return stack[top--];
    }
}

int isBalanced(char *expr) {
    char x;
    for (int i = 0; expr[i] != '\0'; i++) {
       
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }
        
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            
            if (top == -1) {
                return 0;
            }
            x = pop();
           
            if ((expr[i] == ')' && x != '(') ||
                (expr[i] == ']' && x != '[') ||
                (expr[i] == '}' && x != '{')) {
                return 0;
            }
        }
    }
   
    return (top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);


    expr[strcspn(expr, "\n")] = '\0';

    
    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is unbalanced.\n");
    }

    return 0;
}

/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push function
void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop function
int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluate(char postfix[])
{
    char *token = strtok(postfix, " ");

    while(token != NULL)
    {
        // If operand
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1])))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();

            switch(token[0])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    int result = evaluate(postfix);

    printf("Result = %d", result);

    return 0;
}
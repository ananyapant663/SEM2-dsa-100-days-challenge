/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100];
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    int i = 0;

    while((ch = infix[i++]) != '\0')
    {
        if(isalnum(ch))   // operand
        {
            printf("%c", ch);
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
                printf("%c", pop());
            pop(); // remove '('
        }
        else   // operator
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                printf("%c", pop());
            push(ch);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}
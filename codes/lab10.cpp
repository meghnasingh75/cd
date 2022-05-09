/*
Algorithm:
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else, a) If the precedence and associativity of the scanned operator is greater than the
precedence and associativity of the operator in the stack(or the stack is empty or the stack
contains a ‘(‘ ), push it.
b) ‘^’ operator is right associative and other operators like ‘+’,’-‘,’*’ and ‘/’ are left
associative. Check especially for a condition when both top of the operator stack and
scanned operator are ‘^’. In this condition the precedence of the scanned operator is higher
due to its right associativity. So it will be pushed in the operator stack. In all the other cases
when the top of the operator stack is the same as the scanned operator we will pop the
operator from the stack because of left associativity due to which the scanned operator has
less precedence.
c) Else, Pop all the operators from the stack which are greater than or equal to in precedence
than that of the scanned operator. After doing that Push the scanned operator to the stack.
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and
discard both the parenthesis.
6. Repeat steps 2-6 until the infix expression is scanned.
7. Print the output.
8. Pop and output from the stack until it is not empty.
*/


#define SIZE 50
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char s[SIZE];
int top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return -1;
}

char *strrev(char *str)
{
    if (!str)
    {
        fprintf(stderr, "%s() Error: invalid string\n", __func__);
        return NULL;
    }
    char *begin = str;
    char *end = *begin ? str + strlen(str) - 1 : begin;
    char tmp;
    while (end > begin)
    {
        tmp = *end;
        *end-- = *begin;
        *begin++ = tmp;
    }
    return str;
}

int main()
{
    char infx[50], prfx[50], ch, elem;
    int i = 0, k = 0;
    printf("\nRead the Infix Expression: ");
    scanf("%s", infx);
    push('#');
    strrev(infx);
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == ')')
            push(ch);
        else if (isalnum(ch))
            prfx[k++] = ch;
        else if (ch == '(')
        {
            while (s[top] != ')')
                prfx[k++] = pop();
            elem = pop();
        }
        else
        { 
            while (pr(s[top]) >= pr(ch))
                prfx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        prfx[k++] = pop();
    prfx[k] = '\0';
    strrev(prfx);
    strrev(infx);
    printf("\nGiven Infix Expn: %s \nPrefix Expn: %s", infx, prfx);
    return 0;
}

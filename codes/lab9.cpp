/*
1. Start the program.
2. Get the Set of Productions for the grammar from the user. No redundant & cyclic
productions must be given.
3. Reverse each input productions and print it.
4. The conditions to be checked according to the reversed inputs are:
1. Conditions Inclusions in result
S->Sa add a
S->Aa add a, production of A
S->ab add a
S->AB Production of A
S->SA none
S->a take a
S->SA* none taken
S->*a take * leave a
5. Print the Trailing edges.
6. Stop the program.
*/

#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1) return -1;
    else return stack[top--];
}

int priority(char x)
{
    if(x == '(') return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    
    return -1;
}

int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x =
                        pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}

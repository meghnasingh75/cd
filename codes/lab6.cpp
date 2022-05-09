/*
1. Start the Process.
2. Symbols from the input are shifted onto stack until a handle appears on top of the
stack.
3. The Symbols that are the handle on top of the stack are then replaces by the
left-hand side of the production (reduced).
4. If this result in another handle on top of the stack, then another reduction is done,
otherwise we go back to shifting.
5. This combination of shifting input symbols onto the stack and reducing productions
when handles appear on the top of the stack continues until all of the input is
consumed and the goal symbol is the only thing on the stack - the input is then
accepted.
6. If we reach the end of the input and cannot reduce the stack to the goal symbol, the
input is rejected.
7. Stop the process.
*/


#include <stdio.h>
#include <conio.h>
#include <string.h>

void check();
void check1();
void copy();
void print(int val);
char stack[20];
char temp[10];
char result[10];
int i, j;

int main()
{
    printf("Enter Your Expression:");
    scanf("%s", &stack);
    check();
    return 0;
}

void check()
{
    for (; i < strlen(stack) + 1; i++)
    {
        if (stack[i] == '+' || stack[i] == '-' || stack[i] == '*' || stack[i] == '/' || stack[i] == '\0')
        {
            temp[j] = 'E';
            j++;
            temp[j] = stack[i];
            j++;
        }
    }
    check1();
}

void check1()
{
    printf("\n STACK VALUES\tINPUT \n");
l:
    for (j = 0, i = 0; i < strlen(temp);)
    {
        if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/')
        {
            printf("\n\t %c", temp[i]);
            i++;
            print(i);
            printf("\n\t %c", temp[i]);
            i++;
            print(i);
            i--;
            copy();
            goto l;
        }
        else
        {
            printf("\n\t %c", temp[i]);
            i++;
            print(i);
        }
    }
    printf("\n\n\t Expressions Output:%s", temp);
}

void copy()
{
    j = 0;
    while (temp[i] != '\0')
    {
        temp[j] = temp[i];
        j++;
        i++;
    }
    temp[j] = '\0';
}

void print(int val)
{
    printf("\t\t");
    for (; val < strlen(temp); val++)
        printf("%c", temp[val]);
}

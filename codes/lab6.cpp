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

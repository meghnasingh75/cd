#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main()
{
    char g, exp[20], stack[20];
    int m = 0, i, top = -1, flag = 0, len, j;
    cout << "\nInput an expression : ";
    gets(exp);
    cout << "\nIntermediate code generator\n";
    len = strlen(exp);
    if (isdigit(exp[len - 1]))
    {
        cout << "T = inttoreal(";
        i = len - 1;
        while (isdigit(exp[i]))
        {
            i--;
        }
        for (j = i + 1; j < len; j++)
        {
            cout << exp[j];
        }
        cout << ".0)\n";
        exp[i + 1] = 'T';
        len = i + 2;
    }
    else
    {
        cout << "T = " << exp[len - 1] << "\n";
        exp[len - 1] = 'T';
    }
    for (i = len - 1; i >= 0; i--)
    {
        if (exp[i] == '=')
        {
            if ((i - 1) == 0)
            {
                if (isalpha(stack[top]))
                {
                    cout << exp[i - 1] << " " << exp[i] << " " << stack[top];
                }
                else
                {
                    cout << exp[i - 1] << " " << exp[i] << " " << stack[top] << stack[top - 1];
                }
                break;
            }
            else
            {
                cout << "\nWrong Expression !!!";
                break;
            }
        }
        if (exp[i] == '+' || exp[i] == '/' || exp[i] == '*' || exp[i] == '-' || exp[i] == '%')
        {
            if (flag == 0)
            {
                flag = 1;
                top = top + 1;
                stack[top] = exp[i];
            }
            else
            {
                g = char('A' + m);
                m++;
                cout << g << " = " << stack[top] << stack[top - 1] << "\n";
                stack[top - 1] = g;
                stack[top] = exp[i];
                flag = 0;
            }
        }
        else
        {
            top = top + 1;
            stack[top] = exp[i];
            if (top > 1)
            {
                g = char('A' + m);
                m++;
                cout << g << " = " << stack[top] << stack[top - 1] << stack[top - 2] << "\n";
                top = top - 2;
                stack[top] = g;
                flag = 0;
            }
        }
    }
}

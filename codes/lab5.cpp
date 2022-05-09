/*
1. Start the process.
2. Input an expression EXP from user.
3. Process the expression from right hand side to left hand side.
4. FLAG:=0; TOP = -1;
5. IF EXP = ‘=’ then
i. IF EXP(index – 1) = 0 then
1. PRINT EXP element from index to (index – 1) and POP
STACK[TOP]. Terminate
Else
i. PRINT Wrong Expression
[EndIF]
IF an operator is found and FLAG = 0 then
i. TOP:= TOP + 1
ii. add to STACK[TOP].
iii. FLAG:=1
Else
i. pop twice the STACK and result add to the newID(identifier) and
PRINT.
ii. TOP:=TOP-2. Save newID to STACK[TOP]
iii. FLAG:=0
[EndIF]
6. IF an operand is found then
i. TOP:=TOP+1
ii. move to STACK [TOP]
iii. IF TOP > 1 then
1. pop twice the STACK and result add to the newID(identifier)
and PRINT.
2. TOP:=TOP-2. Save newID to STACK[TOP]
3. FLAG:=0
[End]
7. End the process
*/
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

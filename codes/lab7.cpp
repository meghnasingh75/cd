#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char av[100], av1[100];
int v = 0, j = 0, v1 = 0;

void disp(int);

struct pro
{
    char h, t, t1;
} p[100];

int search(char x)
{
    for (int i = 0; i < v; i++)
        if (av[i] == x)
            return 1;
    return 0;
}

int search1(char x)
{
    for (int i = 0; i < v1; i++)
        if (av1[i] == x)
            return 1;
    return 0;
}

void disp1(char x)
{
    for (int i = 0; i < j; i++)
        if (p[i].h == x)
            disp(i);
}

void disp(int px)
{
    if (int(p[px].t) >= 65 && int(p[px].t) <= 90)
    {
        if (p[px].t1 != '\0' && search1(p[px].t1) == 0)
        {
            if (p[px].t1 != '\n')
                cout << p[px].t1;
            av1[v1] = p[px].t1;
            v1++;
        }
        disp1(p[px].t);
    }
    else if (p[px].t != '#')
    {
        if (search1(p[px].t) == 0)
        {
            cout << "\t" << p[px].t;
            av1[v1] = p[px].t;
            v1++;
        }
    }
}

int main()
{
    int i, k;
    cout << "Enter the production: end with ~" << endl
         << endl;
    char a1[100];
    for (i = 0; (a1[i] = getc(stdin)) != '~'; i++)
        ;
    a1[i] = '\0';
    cout << a1;
    for (k = 0; k < i; k++)
    {
        if (a1[k] == '-' && a1[k + 1] == '>')
        {
            p[j].h = a1[k - 1];
            p[j].t = a1[k + 2];
            p[j].t1 = '\0';
            if (p[j].h == p[j].t)
            {
                p[j].t = a1[k + 3];
                if (int(p[j].t) >= 65 && int(p[j].t) <= 90)
                    p[j].t = '#';
                p[j].t1 = '\0';
            }
            else if (int(p[j].t) >= 65 && int(p[j].t) <= 90)
            {
                p[j].t1 = a1[k + 3];
                if ((int(p[j].t1) >= 65) && (int(p[j].t1) <= 90))
                    p[j].t1 = '\0';
            }
            j++;
        }
    }
    cout << endl << "The Leading edges r as follows : " << endl;
    for (i = 0; i < j; i++)
    {
        if (search(p[j].h) == 0)
        {
            av[v] = p[i].h;
            cout << endl
                 << av[v] << ": {";
            disp1(av[v]);
            cout << " }" << endl
                 << endl;
            for (k = 0; k < v1; k++)
                av1[k] = '\0';
            v1 = 0;
            v++;
        }
    }
    return 0;
}

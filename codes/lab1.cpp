#include <stdio.h>
#include <stdlib.h>

struct setStates
{
    int state;
    int final;
    int start;
};

typedef struct setStates sstate;

int main()
{
    int s, v, i, j;
    int **sv, *var;
    sstate *states;
    printf("\nInput the number of finite set of states : ");
    scanf("%d", &s);
    printf("\nInput the number of finite set of input variables : ");
    scanf("%d", &v);
    sv = (int **)malloc(v * sizeof(int));
    for (i = 0; i < s; i++)
    {
        sv[i] = (int *)malloc(sizeof(int));
    }
    states = (sstate *)malloc(s * sizeof(sstate));
    printf("\nInput the states and its info (state start final): \n");
    for (i = 0; i < s; i++)
    {
        scanf("%d%d%d", &states[i].state, &states[i].start, &states[i].final);
    }
    var = (int *)malloc(v * sizeof(int));
    printf("\nInput the variables : \n");
    for (i = 0; i < v; i++)
    {
        scanf("%d", &var[i]);
    }
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("\nThe states %c with input variable %c move to state : ", states[i].state, var[j]);
            scanf("%d", &sv[i][j]);
        }
    }
    printf("\nThe Transition Table : \n");
    printf("\t");
    for (i = 0; i < v; i++)
    {
        printf("%c\t", var[i]);
    }
    printf("\n------------------------------------------------");
    for (i = 0; i < s; i++)
    {
        printf("\n%c %c %c\t", states[i].state, (states[i].start == 0) ? ' ' : '$', (states[i].final == 0) ? ' ' : '*');
        for (j = 0; j < v; j++)
        {
            printf("%c\t", sv[i][j]);
        }
        printf("\n");
    }

    return 0;
}

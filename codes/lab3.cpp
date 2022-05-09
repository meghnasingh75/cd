/*
Algorithm:
If x is a terminal, then FIRST(x) = { ‘x’ }
If x-> Є, is a production rule, then add Є to FIRST(x).
If X->Y1 Y2 Y3....Yn is a production,
FIRST(X) = FIRST(Y1)
If FIRST(Y1) contains Є then FIRST(X) = { FIRST(Y1) – Є } U { FIRST(Y2) }
If FIRST (Yi) contains Є for all i = 1 to n, then add Є to FIRST(X).

Procedure First
1. Input the number of production N.
2. Input all the production rule PArray
3. Repeat steps a, b, c until processes all input production rule i.e. PArray[N]
a. If Xi ≠ Xi+1 then
i. Print Result array of Xi which contain FIRST(Xi)
b. If first element of Xi of PArray is Terminal or ε Then
i. Add Result = Result U first element
c. If first element of Xi of PArray is Non-Terminal Then
i. searchFirst(i, PArray, N)
4. End Loop
5. If N (last production) then
a. Print Result array of Xi which contain FIRST(Xi)
6. End

Procedure searchFirst(i, PArray, N)
1. Repeat steps Loop j=i+1 to N
a. If first element of Xj of PArray is Non-Terminal Then
i. searchFirst(j, of PArray, N)
b. If first element of Xj of PArray is Terminal or ε Then
i. Add Result = Result U first element
ii. Flag=0
2. End Loop
3. If Flag = 0 Then
a. Print Result array of Xj which contain FIRST(Xj)
*/


#include<bits/stdc++.h>
using namespace std;

void searchFirst(int n, int i, char pl[], char r[], char result[], int k) {
    int j, flag;
    for(j = i + 1; j < n; j++) {
        if(r[i] == pl[j]) {
            if(isupper(r[j])) {
                searchFirst(n, j, pl, r, result, k);
            }
            if(islower(r[j]) || r[j] == '+' || r[j] == '*' || r[j] == ')' || r[j] == '(') {
                result[k++] = r[j];
                result[k++] =','; 
                flag = 0;
            }
        }
    }
    if(flag == 0) {
        for(j = 0; j < k - 1; j++) {
            cout << result[j];
        }
    }
}

int main() {
    char pr[10][10], pl[10], r[10], prev, result[10];
    int i, n, k, j;
    cout << "\nHow many production rule : ";
    cin >> n;
    if(n == 0) {
        exit(0);
    }
    for(i = 0; i < n; i++) {
        cout << "Input left part of production rules : ";
        cin >> pl[i];
        cout << "Input right part of production rules : ";
        cin >> pr[i];
        r[i] = pr[i][0];
    }
    cout << "\nProduction Rules are :\n";
    for (i = 0; i < n; i++) {
        cout << pl[i] << " -> " << pr[i] << "\n"; //<<";"<<r[i]<<"\n";
    }
    cout << "\n---O U T P U T---\n";
    prev = pl[0];
    k = 0;
    for (i = 0; i < n; i++) {
        if (prev != pl[i]) {
            cout << "\nFIRST ( " << prev << " ) = { ";
            for( j = 0; j < k - 1; j++) {
                cout << result[j];
            }
            cout << " }";
            k = 0;
            prev = pl[i];
        }
        if (prev == pl[i]) {
            if (islower(r[i]) || r[i] == '+' || r[i] == '*' || r[i] == ')' || r[i] == '(') {
                result[k++] = r[i];
                result[k++] = ',';
            }
            if (isupper(r[i])) {
                cout << "\nFIRST ( " << prev << " ) = { ";
                searchFirst(n, i, pl, r, result, k);
                cout << " }";
                k = 0;
                prev = pl[i+1];
            }
        }
    }
    if (i == n) {
        cout << "\nFIRST ( " << prev << " ) = { ";
        for(j = 0; j < k - 1; j++) {
            cout << result[j];
        }
        cout << " }";
        k = 0;
        prev = pl[i];
    }
    return 0;
}

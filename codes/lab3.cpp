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

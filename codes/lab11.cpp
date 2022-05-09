/*
Algorithm:
Input: It contains a basic block
Output: It contains the following information:
Each node contains a label. For leaves, the label is an identifier.
Each node contains a list of attached identifiers to hold the computed values.
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string exp;
    cout << "Enter the expression:-";
    cin >> exp;
    int j = 0, k = 0;
    char q;
    for (int i = exp.length() - 1; i > 1; i--)
    {
        if (islower(exp[i]) || (exp[i] >= 48 && exp[i] <= 57))
        {
            cout << j << "->" << exp[i] << endl;
            j++;
        }
    }
    for (int i = exp.length() - 1; i > 1; i--)
    {
        if (!(islower(exp[i]) || (exp[i] >= 48 && exp[i] <= 57)))
        {
            cout << j << "->" << exp[i] << k << k + 1 << endl;
            j++;
            k += 2;
        }
    }
    cout << j << "->" << exp[0] << endl;
    j++;
    cout << j << "->" << exp[1] << j - 1 << j - 2 << endl;
    return 0;
}

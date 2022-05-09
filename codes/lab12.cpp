#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int flag = 0;
    map<char, vector<string>> rules;
    string exp, test;
    rules['S'].push_back("aAc");
    rules['A'].push_back("cd");
    rules['A'].push_back("d");
    cout << "Enter the string: ";
    cin >> exp;
    string start = "aAc";
    if (start[0] != exp[0])
        cout << "Not Accepted";
    else
    {
        cout << "S" << endl
             << start << endl;
        string a = (rules['A'])[0];
        string b = (rules['A'])[1];
        string t;
        t = start[0] + a + start[2];
        cout << t << endl;
        if (t == exp)
        {
            flag = 1;
            cout << "Accepted";
        }
        else
        {
            cout << start << endl;
            t = start[0] + b + start[2];
            cout << t << endl;
            if (t == exp)
            {
                flag = 1;
                cout << "Accepted";
            }
        }
    }
    if (flag == 0)
        cout << "Not accepted";
    return 0;
}

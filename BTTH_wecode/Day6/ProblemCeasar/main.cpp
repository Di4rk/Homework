#include <bits/stdc++.h>
using namespace std;

int main()
{
    long k;
    cin >> k;
    cin.ignore();
    string x;
    getline(cin,x);
    for(char *i= &x[0] ; i< &x[0] + x.length() ; i++)
    {
        if(*i>= 'A' && *i<='Z') *i = (int)((*i - 'A' + k)%26) + 'A';
    }
    cout << x;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long x1,x2,v1,v2;
    float t;
    cin >> x1 >> v1 >> x2 >> v2;
    t = 1.0*(x2-x1)/(v1-v2);
    if (t>=0) cout << "YES";
    else cout << "NO";
}

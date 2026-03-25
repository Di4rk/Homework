#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool> present(n+1, false);
    int mex = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if (x <= n)
            present[x] = true;
        while(mex <= n && present[mex]) mex++;
        cout << mex << " ";
    }
    return 0;
}
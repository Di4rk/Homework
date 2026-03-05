#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int pos = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        cout << -1;
        return 0;
    }
    cout << pos << endl;            
    cout << pos + 1 << endl;         
    cout << n - 1 - pos << endl;     
    cout << n - pos << endl;

    return 0;
}
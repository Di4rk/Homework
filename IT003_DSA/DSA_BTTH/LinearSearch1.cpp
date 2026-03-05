#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &k : a) cin >> k;
    int x;
    cin >> x;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == x) {
            cout << i << endl;
            cout << i+1 << endl;
            break;
        }
    }
    int j = 0;
    for(int i = n-1;i>= 0; i--){
        if(a[i] == x){
            cout << j << endl;
            cout << j + 1 << endl;
            break; 
        }
        j++;
    }
    if(!j) cout << -1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,k,b,m,n;
    cin >> a >> k >> b >> m >> n; 
    long i = 0, sum = 0;
    while(true){
        if(sum >= n){
            cout << i;
            return 0;
        }        
        i++;
        if(i % k != 0) sum += a;
        if(i % m != 0) sum += b;
    }
    return 0;
}
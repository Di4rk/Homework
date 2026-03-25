#include <bits/stdc++.h>
using namespace std;
bool check(long long x, long long a, long long k, long long b ,long long m, long long n){
    long long daya = x - x / k;
    long long dayb = x - x / m;
    
    __int128 total = (__int128)daya * a + (__int128)dayb * b;
    return total >= n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,k,b,m,n;
    cin >> a >> k >> b >> m >> n; 
    long long left = 0, right = LLONG_MAX, midle;
    long long ans = midle;
    while(left <= right){
        midle = (left + right) /2;
        if(check(midle,a,k,b,m,n)){
            ans = midle;
            right = midle -1;
        }
        else{
            left = midle + 1;
        }
    }
    cout << ans;
    return 0;
}
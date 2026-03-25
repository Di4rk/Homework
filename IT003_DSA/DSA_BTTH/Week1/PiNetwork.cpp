#include <bits/stdc++.h>
using namespace std;
bool check(long mid, vector<long>& ban, vector<long>& mua){
    auto itban = upper_bound(ban.begin(),ban.end(),mid);
    long nguoiban = itban - ban.begin();

    auto itmua = lower_bound(mua.begin(), mua.end(), mid);
    long nguoimua = mua.end() - itmua;
    return nguoiban >= nguoimua;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<long> ban(n);
    vector<long> mua(m);
    for(long &k : ban) cin >> k;
    for(long &k : mua) cin >> k;
    sort(ban.begin(), ban.end());
    sort(mua.begin(), mua.end());
    long left = 0, right = LONG_MAX, mid;
    long ans = right;
    while(left <= right){
        mid = (left + right)/2;
        if(check(mid,ban,mua)){
            ans = mid;
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
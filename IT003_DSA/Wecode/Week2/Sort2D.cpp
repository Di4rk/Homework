#include <bits/stdc++.h>
using namespace std;

void mySort(vector<pair<int,int>> &Diem,int n){
    for(int i = 1; i < n; i++){
        for(int k = i-1; k >= 0; k--){
            if (Diem[k].first > Diem[k+1].first) swap(Diem[k],Diem[k+1]);
            if (Diem[k].first == Diem[k+1].first && Diem[k].second < Diem[k+1].second ) swap(Diem[k],Diem[k+1]);
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> Diem(n);
    for(auto &x : Diem){
        cin >> x.first;
        cin >> x.second;
    }
    mySort(Diem, n);
    for(auto &x : Diem){
        cout << x.first << " " << x.second  << "\n\n";
    }
    return 0;
}
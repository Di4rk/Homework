#include <bits/stdc++.h>
using namespace std;

void mySort(vector<int>& a, int n){
    for(int i= 0;i<n;i++){
        int min_inx = i;
        for(int j = i;j<n;j++){
            if(a[min_inx] > a[j]) min_inx = j;
        }
        if(i != min_inx){
            swap(a[i], a[min_inx]);
            for(int k : a){
                cout << k << " ";
            }
            cout << endl << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    mySort(a,n);
}
#include <bits/stdc++.h>
using namespace std;
void mySort(vector<int>& a, int n){
    for(int i = 1;i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
            for(int k : a) cout << k << " ";
            cout << endl;
        }
        a[j+1] = key;
        for(int k : a) cout << k << " ";
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    mySort(a ,n);
}
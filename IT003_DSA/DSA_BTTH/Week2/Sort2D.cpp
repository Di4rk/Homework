#include <bits/stdc++.h>
using namespace std;

bool isBetter(pair<int,int> idx1, pair<int,int> idx2){
    if(idx1.first != idx2.first)
        return idx1.first < idx2.first;
    return idx1.second > idx2.second;
}

void merge(vector<pair<int,int>> &diem, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int,int>> L(n1), R(n2);
    for(int i = 0; i < n1; i++) L[i] = diem[i + left];
    for(int j = 0; j < n2; j++) R[j] = diem[mid + j + 1];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(isBetter(L[i],R[j])) diem[k++] = L[i++];
        else diem[k++] = R[j++];            
    }

    while(i < n1) diem[k++] = L[i++];
    while(j < n2) diem[k++] = R[j++];
}

void mergeSort(vector<pair<int,int>> &diem, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(diem, left, mid);
    mergeSort(diem, mid + 1, right);
    merge(diem, left, mid, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> diem(n);
    for(auto &x : diem){
        cin >> x.first >> x.second;
    }

    mergeSort(diem, 0, n - 1);

    for(auto &x : diem){
        cout << x.first << " " << x.second << "\n\n";
    }
    return 0;
}
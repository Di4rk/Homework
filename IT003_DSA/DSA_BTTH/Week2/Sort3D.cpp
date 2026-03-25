#include <bits/stdc++.h>
using namespace std;

bool isBetter(tuple<int,int,int> idx1, tuple<int,int,int> idx2){
    auto &[x1,y1,z1] = idx1;
    auto &[x2,y2,z2] = idx2;

    if(x1 != x2) return x1 < x2;
    else if (y1 != y2) return y1 > y2;
    else return z1 < z2;
}

void merge(vector<tuple<int,int,int>> &diem, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<tuple<int,int,int>> L(n1), R(n2);
    for(int i = 0; i < n1; i++) L[i] = diem[left + i];
    for(int j = 0; j < n2; j++) R[j] = diem[mid + j + 1];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(isBetter(L[i],R[j])) diem[k++] = L[i++];
        else diem[k++] = R[j++];
    }

    while(i < n1) diem[k++] = L[i++];
    while(j < n2) diem[k++] = R[j++];
}

void mergeSort(vector<tuple<int,int,int>> &diem, int left, int right){
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
    vector<tuple<int,int,int>> diem(n);
    for(auto &[x,y,z] : diem){
        cin >> x >> y >> z;
    }

    mergeSort(diem, 0, n - 1);

    for(auto &[x,y,z] : diem){
        cout << x << " " << y << " " << z << "\n\n";
    }
    return 0;
}
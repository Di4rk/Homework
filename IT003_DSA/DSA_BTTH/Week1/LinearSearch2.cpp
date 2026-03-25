
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void heapity(vector<int>& arr, int n, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapity(arr, n, largest);
    }
}
void myHeapSort(vector<int>& arr){
    int n = arr.size();
    for(int i = n / 2 -1; i >= 0; i--){
        heapity(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapity(arr, i, 0);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> mang(n);
        for(int &a : mang) cin >> a;
        myHeapSort(mang);
        if(n==2) cout << (mang[n-1] - mang[0]) << endl;
        else {
        cout << (mang[n-1] - mang[0]) + (mang[n-2] - mang[1]) << endl;
    }
    }
}

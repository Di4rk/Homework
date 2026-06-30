#include <bits/stdc++.h>
using namespace std;

void mysorrt(vector<string> &x, int low, int high);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> idk(n);
    for(int i = 0; i < n; ++i) {
        cin >> idk[i];
    }

    mysorrt(idk, 0, n - 1);

    int count = 1;
    for(int i = 1; i < n; ++i) {
        if(idk[i] != idk[i- 1]) {
            ++count;
        }
    }

    cout << count;
    return 0;
}

int quicksorrt(vector<string>& x, int low, int high) {
    string pivot = x[high];
    int i = low - 1;

    for(int j = low; j < high; ++j) {
        if(x[j] < pivot) {
            ++i;
            swap(x[i], x[j]);
        }
    }
    swap(x[i+1], x[high]);
    return i + 1;
}

void mysorrt(vector<string>& x, int low, int high) {
    if(low < high) {
        int pi = quicksorrt(x, low, high);

        mysorrt(x, low, pi - 1);
        mysorrt(x, pi + 1, high);
    }
}
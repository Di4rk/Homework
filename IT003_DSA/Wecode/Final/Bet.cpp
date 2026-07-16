#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct CLB{ 
    string name;
    int PT, GF, GA, YC, RC, ranking;
};

int compare(CLB &a, CLB &b) {

    if(a.PT != b.PT) {
        return (a.PT > b.PT) ? -1 : 1;
    }

    if(a.GF - a.GA != b.GF - b.GA) {
        return (a.GF - a.GA  > b.GF - b.GA) ? -1 : 1;
    }

    if(a.GA != b.GA) {
        return (a.GA > b.GA) ? -1 : 1;
    }

    if((a.YC + 2 * a.RC) != (b.YC + 2*b.RC)) {
        return ((a.YC + 2 * a.RC) < (b.YC + 2*b.RC)) ? -1 : 1;
    }

    if(a.ranking != b.ranking) {
        return (a.ranking < b.ranking) ? -1 : 1;
    }

    return 0;

}

void Nhap(CLB &x) {
    cin >> x.name >> x.PT >> x.GF >> x.GA >> x.YC >> x.RC >> x.ranking;
}
void NhapDuDoan(CLB &x) {
    cin >> x.PT >> x.GF >> x.GA >> x.YC >> x.RC >> x.ranking;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    CLB *a;
    a = new CLB[n];
    for(int i = 0; i < n; ++i) {
        Nhap(a[i]);
    }

    int k;
    cin >> k;
    while(k--) {
        CLB x;
        NhapDuDoan(x);

        int left = 0;
        int right = n-1;

        bool find = false;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int res = compare(a[mid], x);

            if(res == 0){
                cout << "CO\n";
                find = true;
                break;
            }
            else if(res < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(!find) {
            cout << "KHONG\n";
        }

    }
}
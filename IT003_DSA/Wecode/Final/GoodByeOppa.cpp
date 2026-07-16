#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct country{
    string name;
    int PT, GF, GA, YC, RC, ranking;
};

bool compare(const country &a, const country &b) {
    if(a.PT != b.PT) {
        return (a.PT > b.PT) ? 1 : 0;
    }
    if(a.GF - a.GA != b.GF - b.GA) {
        return (a.GF - a.GA > b.GF - b.GA) ? 1 : 0;
    }
    if(a.GA != b.GA) {
        return (a.GA > b.GA) ? 1 : 0;
    }
    int fa = a.YC + 2 * a.RC;
    int fb = b.YC + 2 * b.RC;
    if(fa != fb) {
        return (fa < fb) ? 1 : 0;
    }
    if(a.ranking != b.ranking) {
        return (a.ranking < b.ranking) ? 1 : 0;
    }

    return 0;
}

void Nhap(country &x) {
    cin >> x.name >> x.PT >> x.GF >> x.GA >> x.YC >> x.RC >> x.ranking;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    country *a = new country[n];
    for(int i =0; i < n; ++i) {
        Nhap(a[i]);
    }

    sort(a, a + n, compare);

    for(int i = 0; i < 8; ++i) {
        cout << a[i].name << " " << a[i].PT << " " << a[i].GF << " " << a[i].GA << " " << a[i].YC << " " << a[i].RC << " " <<a[i].ranking << "\n";
    }

}
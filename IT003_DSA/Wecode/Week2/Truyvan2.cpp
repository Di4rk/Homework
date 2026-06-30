    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n,q;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> firstt, endd;
            for(int i = 0; i < n; ++i) {
                cin >> a[i];
                if(firstt.find(a[i]) != firstt.end()) {
                    firstt[a[i]] = i + 1;
                }   
                endd[a[i]] = i + 1;
            }
        cin >> q;
        while(q--) {
            int type, x;
            cin >> type >> x;
            if(type == 1) {
                if(firstt.find(x) != firstt.end()) {
                    cout << firstt[x] << "\n";
                } else {
                    cout << -1 << "\n";
                }
            } else if (type == 2) {
                if(endd.find(x) != endd.end()) {
                    cout << endd[x] << "\n";
                } else {
                    cout << -1 << "\n";
                }
            }
        }
        return 0;
    }
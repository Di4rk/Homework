#include <bits/stdc++.h>
using namespace std;

class room {
    protected:
        string name;
        int tang, sophong, succhua;
    public:
        virtual void Nhap() {
            cin >> name >> tang >> sophong >> succhua;
        };
        virtual int getsucchua() {return succhua;};
        virtual int gettang() {return tang;};
        virtual int getsophong() {return sophong;};
        virtual string getten() {return name;};
};

class lt : public room {
    private:
        int maylanh;
    public:
        void Nhap() override {
            room::Nhap();
            cin >> maylanh;
        }
};

class th : public room {
    private:
        int computers;
    public:
        void Nhap() override {
            room::Nhap();
            cin >> computers;
        }
};

class gd : public room {
    private:
        int displays;
    public:
        void Nhap() override {
            room::Nhap();
            cin >> displays;
        }
};

class dsach {
    private:
        vector<room*> list;
    public:
        void Nhap(int n){
            for(int i = 0; i < n; ++i){
                int loai;
                cin >> loai;
                
                room* r = nullptr;
                switch (loai) {
                    case 1:
                        r = new lt();
                        break;
                    case 2:
                        r = new th();
                        break;
                    case 3: 
                        r = new gd();
                        break;
                    default:
                        r = nullptr;
                        break;
                }

                if(r != nullptr) {
                    r->Nhap();
                    list.push_back(r);
                }
            }
        };

        int tong() {
            int tong = 0;
            for(auto r : list) {
                tong += r->getsucchua();
            }
            return tong;
        }

        room* phongKhitNhat(int k) {
            room* bestroom = nullptr;
            for(auto r : list) {
                if(r->getsucchua() >= k) {
                    if(bestroom == nullptr) {
                        bestroom = r;
                    } else {
                        if(r -> getsucchua() - k < bestroom -> getsucchua() - k){
                            bestroom = r;
                        }
                        else if(r -> getsucchua() - k == bestroom -> getsucchua() - k) {
                             if(r-> gettang() < bestroom -> gettang()){
                                bestroom = r;
                             }
                             else if(r -> gettang() == bestroom -> gettang() && r -> getsophong() < bestroom -> getsophong()){
                                bestroom = r;
                             }
                        }
                    }
                }
            }
            return bestroom;
        }

        ~dsach() {
            for(auto r: list) {
                delete r;
            }
            list.clear();
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    dsach a; 
    a.Nhap(n);

    int k;
    cin >> k;
    cout << a.tong() << endl;
    room* res = a.phongKhitNhat(k);
    if(res == nullptr) {
        cout << "NULL\n";
    }
    else {
        cout << res ->getten();
    }
    
    return 0;
}
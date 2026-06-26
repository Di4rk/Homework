#include <bits/stdc++.h>
using namespace std;

class charr {
    protected:
        string name;
        int value, atk, def;
        int loai, toc, he;
    public:
        virtual void Nhap() {
            cin >> atk >> def;
        }

        virtual void addbuff(int ak, int df) {
            atk += ak;
            def += df;
        }

        virtual void getvalue() {return value;}
        virtual void getname() {return name;}
        virtual int dmg(int luot) = 0;
};

class jarvan : public charr {
    public:
        jarvan() {
        name = "Jarvan";
        value = 1;
        loai = 1;
        toc = 1;
        he = 1;
        }

        int dmg(int luot) override {
            return luot * def * 2;
        }
};

class Reksai : public charr {
    public:
        Reksai() {
        name = "Reksai";
        value = 2;
        loai = 2;
        toc = 2;
        he = 1;
        }

        int dmg(int luot) override {
            if(luot % 4 == 0) return luot / 4 *(atk * 2);
            return luot * atk;
        }
};

class Sivir : public charr {
    public:
        Sivir() {
        name = "Sivir";
        loai = 3;
        value = 4;
        toc = 1;
        he = 0;
        }

        int dmg(int luot) override {
            return luot * atk * 2;
        }
};

class Illaoi : public charr {
    public:
        Illaoi() {
        name = "Illaoi";
        loai = 4;
        toc = 2;
        value = 1;
        he = 1;
        }

        int dmg(int luot) override {
            return luot * (atk + def) / 2;
        }
};

class danhsach {
    private:   
        vector<charr*> list;
        int check[4];
    public:
        void Nhap(int n) {
            for(int i = 0; i < 4; ++i) {
                check[i] = 0;
            }
            for(int i = 0; i < n; ++i) {
                charr* a;
                int loai;
                cin >> loai;
                if(loai == 1) {
                    a = new jarvan();
                    check[0]++;
                }
                else if(loai == 2) {
                    a = new Reksai();
                    check[1]++;
                }
                else if(loai == 3) {
                    a = new Sivir();
                    check[2]++;
                }
                else if(loai == 4) {
                    a = new Illaoi();
                    check[3]++;
                }

                a->Nhap();
                list.push_back(a);
            }
        }
        void buff() {
            int loaibuff;
            if(check[0] != 0 &&)
        }
        void Xuat(int m) {
            int sumvalue = 0;
            for(auto x : list){
                sumvalue += x->getvalue();
                cout << x->getname() << " - sat thuong gay ra: " << x->dmg(m) << endl;
            }
            cout << "Tong gia tri: " << sumvalue;
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    danhsach a;
    a.Nhap(n);
    a.Xuat(m);
}
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


        virtual int getvalue() {return value;}
        virtual int gettoc() {return toc;}
        virtual int gethe() {return he;}
        virtual string getname() {return name;}
        virtual long long dmg(int luot) = 0;
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

        long long dmg(int luot) override {
            return 1LL * luot * def * 2;
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

        long long dmg(int luot) override {
            return 1LL * (luot - (luot/4)) * atk + (luot/4) * atk * 2;
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

        long long dmg(int luot) override {
            return 1LL * luot * atk * 2;
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

        long long dmg(int luot) override {
            return 1LL * luot * ((atk + def) / 2);
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
            int countdausi = (check[0] > 0) + (check[1] > 0) + (check[3] > 0);
            int counttiencong = (check[1] > 0) + (check[3] > 0);
            int countcongnghe = (check[0] > 0) + (check[2] > 0);

            int buffatkdausi = 0;
            int buffatktiencong = 0;
            int buffatkcongnghe = 0;
            int buffdefcongnghe = 0;
            if(countdausi >= 3) {
                buffatkdausi += 30;
            }
            else if(countdausi >= 2) {
                buffatkdausi += 15;
            } else {
                buffatkdausi += 0;
            }

            if(counttiencong >= 2) {
                buffatktiencong += 30;
            }

            if(countcongnghe >= 2) {
                buffatkcongnghe += 15;
                buffdefcongnghe += 15;
            }

            for(auto x : list) {
                (x->gettoc() == 1) ? x->addbuff(buffatkcongnghe, buffdefcongnghe) : x->addbuff(buffatktiencong, 0);
                if(x->gethe() == 1)  x->addbuff(0, buffatkdausi);
            }
        }

        void Xuat(int m) {
            long long sumvalue = 0;
            for(auto x : list){
                sumvalue += x->getvalue();
                cout << x->getname() << " - sat thuong gay ra: " << x->dmg(m) << endl;
            }
            cout << "Tong gia tri: " << sumvalue;
        }

        ~danhsach() {
            for(auto &x : list) {
                delete x;
            }
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    danhsach a;
    a.Nhap(n);
    a.buff();
    a.Xuat(m);

    return 0;
}
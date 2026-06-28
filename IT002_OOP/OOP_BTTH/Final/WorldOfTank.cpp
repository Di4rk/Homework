//weight
//num_crews
//thapphao - size/num_ammos
//dongco - hp/lit
#include <bits/stdc++.h>
using namespace std;

struct thapphao {
    int type;
    float size;
    int ammos, original_ammos;

    thapphao() : type(0), size(0), ammos(0), original_ammos(0) {}

    thapphao(int t, int numammos) {
        type = t;
        ammos = original_ammos = numammos;
        if(type == 1) size = 152.0;
        else if (type == 2) size = 76.2;
        else if(type == 3) size = 122.0;
        else if (type == 4) size = 130.0;
    }
};

struct dongco {
    int type;
    float hp, lit, original_lit;
    
    float tieuthu(int km, float wei) {
        return (type == 3) ? ((400 / wei) * (km / 100.0)) : ((450 / wei) * (km / 100.0));
    }
    
    dongco() : hp(0), lit(0), original_lit(0) {}

    dongco(int t, int l) {
        type = t;
        lit = original_lit = l;

        if(type == 1) hp = 500.0;
        else if(type == 2) hp = 600.0;
        else if(type == 3) hp = 1000.0;
    }

};

class tank {
    protected:
        float weight;
        int num_crews;
        thapphao tp;
        dongco dc;
        float dan, xang;
    public:
        virtual void Nhap() {
            cin >> weight >> num_crews >> dan >> xang;
        };

        virtual void Xuat() {
            cout << "weight: " << weight << ", number of crews: " << num_crews << ", damage: " << dmg() << ", performance: " << hieusuat() << "%";
        }
        virtual void updatestate(float km, float ammos) {
            tp.ammos = tp.original_ammos - ammos;
            dc.lit = dc.original_lit - dc.tieuthu(km, weight);
        };
        virtual int dmg() = 0;
        virtual float hieusuat() = 0;
};

class SU152 : public tank {
public:
    void Nhap() override {
        tank::Nhap();
        tp = thapphao(1, dan);
        dc = dongco(2, xang);
    }

    void Xuat() override {
        cout << "SU152, ";
        tank::Xuat();
    }

    float hieusuat() override {
        return (float)tp.ammos / tp.original_ammos * 100.0;
    }

    int dmg() override {
        return num_crews / 4.0 * tp.size * tp.ammos;
    }
};

class KV2 : public tank {
    public:
        void Nhap() override {
            tank::Nhap();
            tp = thapphao(2, dan);
            dc = dongco(1, xang);
        }

        void Xuat() override {
        cout << "KV2, ";
        tank::Xuat();
    }

        float hieusuat() override {
            return (float)tp.ammos / tp.original_ammos * 100.0;
    }

        int dmg() override {
            return round(3 * tp.size * tp.ammos);
        }
};

class IS : public tank {
    public: 
        void Nhap() override { 
            tank::Nhap();
            tp = thapphao(3, dan);
            dc = dongco(2, xang);
        }

        void Xuat() override {
        cout << "IS, ";
        tank::Xuat();
    }

        float hieusuat() override {
            return (float)dc.lit / dc.original_lit * 100.0;
        }

        int dmg() override {
            return round(3 * tp.size * tp.ammos);
        }
};

class Object279 : public tank {
    public: 
        void Nhap() override {
            tank::Nhap();
            tp = thapphao(4, dan);
            dc = dongco(3, xang);
        }

        void Xuat() override {
        cout << "Object279, ";
        tank::Xuat();
    }

        float hieusuat() override {
            return num_crews / 4.0 * 100;
        }

        int dmg() override {
        return num_crews / 4.0 * tp.size * tp.ammos;
    }
};

class listtank {
    private:
        vector<tank*> list;
    public:
        void Nhap() {
            int n;
            cin >> n;
            for(int i = 0; i < n; ++i) {
                int loai;
                cin >> loai;
                tank* t;

                if(loai == 1) {
                    t = new SU152();
                }
                else if (loai == 2) {
                    t = new KV2();
                }
                else if(loai ==3) {
                    t = new IS();
                }
                else if(loai == 4){
                    t = new Object279();
                }

                t->Nhap();
                list.push_back(t);
            }

            int km, ammos;
            cin >> km >> ammos;

            for(auto t : list) {
                t->updatestate(km, ammos);
                t->Xuat();
                cout << "\n";
            }

        }
};

int main() {
    listtank squad;
    squad.Nhap();
    return 0;
}
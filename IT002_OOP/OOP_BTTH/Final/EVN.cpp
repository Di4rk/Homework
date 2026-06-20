#include <bits/stdc++.h>
using namespace std;

class energy {
protected:
    int hieusuat;
    int loai;
public:
    virtual void Nhap() {
        cin >> hieusuat;
    }
    virtual void setloai(int l) { loai = l; }
    virtual int hieusuatchuan(int hour, int wind, int cloud) = 0;
    virtual int getloai() { return loai; }
};

class water : public energy {
private:
    int sotomay;
    bool tinhnang;
public:
    void Nhap() override {
        energy::Nhap();
        cin >> sotomay >> tinhnang;
    }
    int hieusuatchuan(int h, int w, int c) override {
        return hieusuat * sotomay;
    } 
    bool getTinhNang() { return tinhnang; }
};

class nhietdo : public energy {
private:
    int thanperhour;
public:
    void Nhap() override {
        energy::Nhap();
        cin >> thanperhour;
    }
    int hieusuatchuan(int h, int w, int c) override {
        return hieusuat * thanperhour;
    }
};

class wind : public energy {
private: 
    int soluongtubin;
    int maxwind;
public:
    void Nhap() override {
        energy::Nhap();
        cin >> soluongtubin >> maxwind;
    }
    int hieusuatchuan(int h, int w, int c) override {
        double thuc_te = (double)hieusuat * w / maxwind;
        return ceil(thuc_te) * soluongtubin; 
    }
};

class solar : public energy {
private:
    int dientich;
public:
    void Nhap() override {
        energy::Nhap();
        cin >> dientich;
    }
    int hieusuatchuan(int h, int w, int c) override {
        if (c == 1 || h >= 18 || h <= 6) return 0;
        
        int phan_tram = 0;
        if (h >= 11 && h <= 13) phan_tram = 100;
        else if (h > 13 && h < 18)  phan_tram = 100 - (h - 13) * 20;
        else if (h > 6 && h < 11)   phan_tram = (h - 6) * 20;
        
        double cong_suat = (double)hieusuat * dientich * phan_tram / 100.0;
        return ceil(cong_suat);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<energy*> danhsachnguon;

    int maxbatter = 0;
    int current_battry = 0;

    for(int i = 0; i < n; ++i) {
        int loai;
        cin >> loai;
        if(loai == 1) {
            water* w = new water();
            w->setloai(loai);
            w->Nhap();
            danhsachnguon.push_back(w);
            if (w->getTinhNang()) {
                maxbatter += w->hieusuatchuan(0, 0, 0);
            }
        }
        else if(loai == 2) {
            nhietdo* nd = new nhietdo();
            nd->setloai(loai);
            nd->Nhap();
            danhsachnguon.push_back(nd);
        }
        else if(loai == 3) {
            wind* w = new wind();
            w->setloai(loai);
            w->Nhap();
            danhsachnguon.push_back(w);
        }
        else {
            solar *sl = new solar();
            sl->setloai(loai);
            sl->Nhap();
            danhsachnguon.push_back(sl);
        }
    }

    int m;
    cin >> m;

    long long Tongtien = 0;
    int dien_gio_truoc = 0;
    int countdown_ra_luoi = 0;

    for (int i = 0; i < m; ++i) {
        int h, w, c, diendancan;
        cin >> h >> w >> c >> diendancan;

        int diensx = 0;
        for (auto nguon : danhsachnguon) { 
            diensx += nguon->hieusuatchuan(h, w, c);
        }

        if(i > 0) {
            if (5 * abs(diensx - dien_gio_truoc) > dien_gio_truoc) {
                countdown_ra_luoi = 2;
            }
        }

        int dienthucte = 0;
        if(countdown_ra_luoi > 0){
            for(auto nguon : danhsachnguon) {
                if(nguon->getloai() == 1 || nguon->getloai() == 2) {
                    dienthucte += nguon->hieusuatchuan(h, w, c);
                }
            }
        } else {
            dienthucte = diensx;
        }

        int diencapchodan = 0;
        if(dienthucte >= diendancan) {
            diencapchodan = diendancan;
            int dienthua = dienthucte - diendancan;
            current_battry += dienthua;
            if(current_battry > maxbatter) current_battry = maxbatter;
        } else {
            int dienthieu = diendancan - dienthucte;
            int dienrut = min(dienthieu, current_battry);
            current_battry -= dienrut;
            diencapchodan = dienthucte + dienrut;
        }
        
        double tile = (double)diencapchodan / diendancan;
        long long giadien = 3000;
        if(tile <= 0.5) giadien = 2000;
        else if(tile <= 0.8) giadien = 2500; 

        Tongtien += (long long)diencapchodan * 1000 * giadien;

        dien_gio_truoc = diensx;
        if(countdown_ra_luoi > 0) countdown_ra_luoi--;
    }

    cout << Tongtien << '\n';

    for(auto nguon : danhsachnguon) delete nguon;
    return 0;
}
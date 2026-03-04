#include <bits/stdc++.h>
using namespace std;

struct DATHUC
{
    float heso[10001] = {0};
    int maxm = 0;
};

DATHUC* Nhap()
{
    DATHUC *d = new DATHUC;
    for (int i = 0; i <= 10000; i++) d->heso[i] = 0;
    d->maxm = 0;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        float hs;
        int mu;
        cin >> hs >> mu;
        d->heso[mu] += hs;
        if(mu > d->maxm) d->maxm = mu;
    }
    return d;
}

double TinhDaThuc(DATHUC B, double x)
{
    int maxmu = B.maxm;
    double S = 0;
    for(int i = maxmu; i >= 0; i--)
    {
        if (B.heso[i] != 0)
            S += B.heso[i] * pow(x, i);
    }
    return S;
}

void Xuat(DATHUC d)
{
    bool notin = true;
    for (int i = d.maxm; i >= 0 ; i--)
    {
        double giatri = d.heso[i];
        if (giatri != 0)
        {
            if(giatri > 0 && notin == false ) cout << '+';
            if(giatri < 0) cout << '-';

            double absgiatri = abs(giatri);
            if(absgiatri != 1 || i == 0)
            {
                cout << absgiatri;
            }

            if (i > 0)
            {
                cout << 'x';
                if (i > 1) cout << '^' << i;
            }
            notin = false;
        }
    }
    if (notin == true) cout << '0';
}

int main() {
    DATHUC *B;
    B = Nhap();

    cout << "Da thuc vua nhap la: ";
    Xuat(*B);

    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
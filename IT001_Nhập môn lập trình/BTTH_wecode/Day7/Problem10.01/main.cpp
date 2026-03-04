#include <bits/stdc++.h>
using namespace std;

struct DATHUC
{
    double heso[10000] = {0};
    int soMulonnhat;
    
};

DATHUC* Nhap()
{
    DATHUC *d = new DATHUC;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        double hs;
        int mu;
        cin >> hs >> mu;
        d->heso[mu] += hs;
        if (mu > d->soMulonnhat) d->soMulonnhat = mu;
    }
    return d;
}

DATHUC Tong2DaThuc(DATHUC *A, DATHUC *B)
{
    DATHUC Tong;
    int maxmu = (A->soMulonnhat > B->soMulonnhat) ? A->soMulonnhat : B->soMulonnhat;
    Tong.soMulonnhat = maxmu;
    for (int i=0; i<= maxmu;i++)
    {
        Tong.heso[i] = A->heso[i] + B->heso[i];
    }
    return Tong;
}

void Xuat(DATHUC d)
{
    bool notin=true;
    for (int i = d.soMulonnhat; i>=0 ; i--)
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
            if (i>0)
            {
                cout << 'x';
                if (i>1) cout << '^' << i;
            }
            notin=false;
        }
    }
    if (notin == true) cout << '0';
}


int main() {
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}

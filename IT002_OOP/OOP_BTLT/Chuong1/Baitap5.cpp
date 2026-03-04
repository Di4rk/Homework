#include <bits/stdc++.h>
using namespace std;
struct NhanVien {
    string maNV;
    string hoTen;
    string phongBan;
    int luongCoBan;
    int thuong;
    int thucLanh;
};
void nhapDSNV(NhanVien ds[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        getline(cin, ds[i].maNV);
        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].phongBan);
        cin >> ds[i].luongCoBan;
        cin >> ds[i].thuong;
        ds[i].thucLanh = ds[i].luongCoBan + ds[i].thuong;
    }
}
void xuat1NV(NhanVien nv) {
    cout << nv.maNV << " - " << nv.hoTen << " - " << nv.phongBan 
         << " - LCB: " << nv.luongCoBan << " - Thuong: " << nv.thuong 
         << " - Thuc lanh: " << nv.thucLanh << "\n";
}
void xuatDSNV(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuat1NV(ds[i]);
    }
}
long long tongThucLanh(NhanVien ds[], int n) {
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].thucLanh;
    }
    return tong;
}
void inNVLuongThapNhat(NhanVien ds[], int n) {
    int minLCB = ds[0].luongCoBan;
    for (int i = 1; i < n; i++) {
        if (ds[i].luongCoBan < minLCB) {
            minLCB = ds[i].luongCoBan;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ds[i].luongCoBan == minLCB) {
            xuat1NV(ds[i]);
        }
    }
}
int demNVThuong(NhanVien ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].thuong >= 1200000) {
            dem++;
        }
    }
    return dem;
}
void hoanVi(NhanVien &a, NhanVien &b) {
    NhanVien tam = a;
    a = b;
    b = tam;
}
void sapXepNV(NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].phongBan > ds[j].phongBan) {
                hoanVi(ds[i], ds[j]);
            } else if (ds[i].phongBan == ds[j].phongBan) {
                if (ds[i].maNV < ds[j].maNV) {
                    hoanVi(ds[i], ds[j]);
                }
            }
        }
    }
}
int main() {
    NhanVien ds[100];
    int n;
    cout << "Nhap so luong nhan vien: ";
    nhapDSNV(ds, n);    
    cout << "\nDanh sach nhan vien: \n";
    xuatDSNV(ds, n);    
    cout << "\na. Tong thuc lanh cua cong ty: " << tongThucLanh(ds, n) << "\n";    
    cout << "\nb. Danh sach nhan vien co luong co ban thap nhat:\n";
    inNVLuongThapNhat(ds, n);    
    cout << "\nc. So luong nhan vien co thuong >= 1200000: " << demNVThuong(ds, n) << "\n";    
    sapXepNV(ds, n);
    cout << "\nd. Danh sach sau khi sap xep (Phong ban tang dan, Ma NV giam dan):\n";
    xuatDSNV(ds, n);    
    return 0;
}
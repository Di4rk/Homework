
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct DOB {
    int D, M, Y;
};

struct HoTen {
    string Ho;
    string Ten;
};

struct SINHVIEN {
    HoTen Name;
    DOB NgaySinh;
    char GioiTinh;
    float GPA;
    int DRL;
};

void NhapHoTen(HoTen &name) {
    getline(cin >> ws, name.Ho);
    getline(cin >> ws, name.Ten);
}

void NhapNgaySinh(DOB &ngay) {
    cin >> ngay.D >> ngay.M >> ngay.Y;
}

void InThongTin(SINHVIEN a) {
    cout << a.Name.Ho << " " << a.Name.Ten << "\n";
    cout << a.GioiTinh << "\n";
    cout << a.NgaySinh.D << " " << a.NgaySinh.M << " " << a.NgaySinh.Y << "\n";
    cout << fixed << setprecision(2);
    cout << a.GPA << " " << a.DRL << "\n";
    cout << "----------------------------\n";
}

void NhapThongTin(SINHVIEN &a) {
    NhapHoTen(a.Name);
    cin >> a.GioiTinh;
    NhapNgaySinh(a.NgaySinh);
    cin >> a.GPA >> a.DRL;
    cin.ignore();
}

void NhapDS(SINHVIEN *A, int n) {
    for (int i = 0; i < n; i++) {
        NhapThongTin(A[i]);
    }
}

void TimKiem(SINHVIEN *, int, SINHVIEN);
void run(SINHVIEN *, int, int);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    cin >> n;

    SINHVIEN *A = new SINHVIEN[n];

    NhapDS(A, n);
    
    cin >> k;

    run(A, n, k);

    delete[] A;
    return 0;
}

int compare(SINHVIEN &a, SINHVIEN &b) {
    if(a.GPA != b.GPA) {
        return (a.GPA > b.GPA) ? -1 : 1;
    }
    if(a.DRL != b.DRL) {
        return (a.DRL > b.DRL) ? -1 : 1;
    }
    if(a.GioiTinh != b.GioiTinh) {
        return (a.GioiTinh > b.GioiTinh) ? -1 : 1;
    }
    if(a.Name.Ten != b.Name.Ten) {
        return (a.Name.Ten < b.Name.Ten) ? -1 : 1;
    }
    if(a.Name.Ho != b.Name.Ho) {
        return (a.Name.Ho < b.Name.Ho) ? -1 : 1;
    }
    if(a.NgaySinh.Y != b.NgaySinh.Y) {
        return (a.NgaySinh.Y < b.NgaySinh.Y) ? -1 : 1;
    }
    if(a.NgaySinh.M != b.NgaySinh.M) {
        return (a.NgaySinh.M < b.NgaySinh.M) ? -1 : 1;
    }
    if(a.NgaySinh.D != b.NgaySinh.D) {
        return (a.NgaySinh.D < b.NgaySinh.M) ? -1 : 1;
    }
    return 0;
}

void TimKiem(SINHVIEN *A, int n, SINHVIEN x) {
    int left = 0;
    int right = n - 1;


    while(left <= right) {
        int mid = left + (right - left) / 2;
        int res = compare(A[mid], x);

        if(res == 0) {
            cout << "CO\n";
            return;
        }
        else if (res < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << "KHONG\n";
    return;
}

void run(SINHVIEN *A, int n, int k) {
    while(k--) {
        SINHVIEN x;
        NhapThongTin(x);

        TimKiem(A, n, x);
    }
    return;
}

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

void NhapThongTin(SINHVIEN &a) {
    NhapHoTen(a.Name);
    cin >> a.GioiTinh;
    NhapNgaySinh(a.NgaySinh);
    cin >> a.GPA >> a.DRL;
    cin.ignore();
}

struct TNode{
    SINHVIEN data;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(SINHVIEN x) {
    TNode *p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}


void NhapDS(Tree &, int);
void XuatDS(Tree &);
int CountGPAInRange(TNode*, float, float);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Tree T;
    CreateTree(T);
    int n;
    cin >> n;
    NhapDS(T, n);
    XuatDS(T);
    cout << CountGPAInRange(T.root, 7.0, 9.0);
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
        return (a.GioiTinh < b.GioiTinh) ? -1 : 1;
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
        return (a.NgaySinh.D < b.NgaySinh.D) ? -1 : 1;
    }
    return 0;
}

void NhapDS(Tree &T, int n) {
    for(int i = 0; i < n; ++i) {
        SINHVIEN x;
        NhapThongTin(x);
        TNode *p = CreateTNode(x);
        if(T.root == nullptr) {
            T.root = p;
            continue;
        }
        TNode *root = T.root;

        while(true) {
            int pes = compare(p -> data, root -> data);
            if(pes == 0) {
                break;
            }
            else if( pes == 1) {
                if(root -> pLeft == nullptr){
                    root -> pLeft = p;
                    break;
                }
                else {
                    root = root -> pLeft;
                }
            }
            else {
                if(root -> pRight == nullptr) {
                    root ->pRight = p;
                    break;
                }
                else {
                    root = root -> pRight;
                }
            }
        }
    }
}

void XuatThongTin(const SINHVIEN &a) {
    cout << a.Name.Ten << " " << fixed << setprecision(2) <<a.GPA << "\n";
    return;
}

void Xuat(TNode* r) {
    if(r == nullptr) return;
    Xuat(r->pRight);
    XuatThongTin(r->data);
    Xuat(r->pLeft);
}

void XuatDS(Tree &T) {
    Xuat(T.root);
}

int CountGPAInRange(TNode *p, float a, float b) {
    if(p == nullptr) return 0;
    int cnt = 0;
    if(p->data.GPA >= a && p->data.GPA <= b) cnt = 1;
    return cnt + CountGPAInRange(p->pLeft, a ,b) + CountGPAInRange(p->pRight,a ,b);
}
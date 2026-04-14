#include <iostream>
#include <string>
using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

bool isBetter(Hocsinh hs1, Hocsinh hs2){
    if(hs1.Ten != hs2.Ten){
        return hs1.Ten > hs2.Ten;
    }
    else {
        return hs1.Hodem > hs2.Hodem; 
    }
}

void InsertNode(TREE &t, Hocsinh x){
    if(t == nullptr) {
        t = CreateTNode(x);
    }
    if(t->data.Ten == x.Ten && t->data.Hodem == x.Hodem) return;
    else if(isBetter(t->data, x)){
        if(t -> left == nullptr) {
            t -> left = CreateTNode(x);
            return;
        }
        else InsertNode(t -> left,x);
    }
    else {
        if(t -> right == nullptr) {
            t -> right = CreateTNode(x);
            return;
        }
        else InsertNode(t->right,x);
    }
}

void LNR(TREE t){
    if(t == nullptr) return;
    LNR(t->left);
    OutputElement(t->data);
    LNR(t->right);
}

int main(){
    int n;
    cin >> n;
    TREE T;
    CreateTree(T);

    while(n--){
        Hocsinh x;
        InputElement(x);
        InsertNode(T, x);
    }

    LNR(T);
    return 0;    
}
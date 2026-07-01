#include <iostream>


#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh {
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};


struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x) {
    cin >> x.MSHS; 
    getline(cin>>ws, x.HoTen);
    cin >> x.Namsinh; 
    cin >> x.Gioitinh; 
    cin >> x.Toan; 
    cin >> x.Ly; 
    cin >> x.Hoa; 
    cin >> x.Anh; 
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

void CreateHashtable(Hashtable &, int, Hocsinh[], int);

int main()
{
    Hashtable ht;
    Hocsinh ds[MAX];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        InputElement(ds[i]);
    }

    CreateHashtable(ht, m, ds, n);

    cout << ht.M << ' ' << ht.n << endl;
    for (int i = 0; i < ht.M; i++) {
        OutputElement(ht.table[i]);
    }

    return 0;
}

void CreateHashtable(Hashtable &HT, int m, Hocsinh ds[], int n) {
    HT.M = m;
    HT.n = 0;
    for(int i = 0; i < m; ++i) {
        HT.table[i].MSHS = EMPTY;
        HT.table[i].HoTen = "";
        HT.table[i].Namsinh = 0;
        HT.table[i].Gioitinh = ' ';
        HT.table[i].Toan = HT.table[i].Anh = HT.table[i].Ly = HT.table[i].Hoa = 0;
    }


    for(int i = 0; i < n; ++i) {
        int base_index = ds[i].MSHS % m; 
        int index = base_index;
        int j = 0;
        bool found_slot = false;

        while(j < m) {
            if(HT.table[index].MSHS == EMPTY || HT.table[index].MSHS == DELETED) {
                found_slot = true;
                break;
            }
            
            if(HT.table[index].MSHS == ds[i].MSHS) {
                HT.table[index] = ds[i]; 
                found_slot = false; 
                break;
            }

            j++;
            index = (base_index + j * j) % m; 
        }

        if(found_slot) {
            HT.table[index] = ds[i];
            HT.n++;
        }
    }
}
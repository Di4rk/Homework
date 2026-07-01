#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct STUDENT {
    int MSSV;
    string HoTen;
    int NamSinh;
    bool GioiTinh;
    double TBK;
};

struct HashTable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    STUDENT* Table;
};

void Insert(HashTable &, STUDENT);
void CreateHashTable(HashTable &, int);
void PrintHashTable(HashTable);
void DeleteHashTable(HashTable &);

void Input(STUDENT &x) {
    cin >> x.MSSV;
    getline(cin >> ws, x.HoTen);
    cin >> x.NamSinh;
    cin >> x.GioiTinh;
    cin >> x.TBK;
}

void Output(STUDENT sv){
    cout << "[" << sv.MSSV << ", " << sv.HoTen << ", " << sv.GioiTinh << ", " << sv.NamSinh << ", " << sv.TBK << "]\n";
}

int main()
{
    HashTable HT;

    int M, n;
    STUDENT sv;

    cin >> M;
    CreateHashTable(HT, M);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(sv);
        Insert(HT, sv);
    }
    PrintHashTable(HT);
    DeleteHashTable(HT);
    return 0;
}

void CreateHashTable(HashTable &HT, int M) {
    HT.Table = new STUDENT[M];
    HT.M = M;
    HT.n = 0;
    for (int i = 0; i < M; i++) {
        HT.Table[i].MSSV = EMPTY;
    }
}

int HashFunction(HashTable HT, int MSSV) {
    return MSSV % HT.M;
}

void PrintHashTable(HashTable HT) {
    for (int i = 0; i < HT.M; i++) {
        STUDENT sv = HT.Table[i];
        if (sv.MSSV != EMPTY)
            Output(sv);
    }
}

void DeleteHashTable(HashTable &HT) {
    delete [] HT.Table;
    HT.Table = NULL;
    HT.M = 0;
    HT.n = 0;
}


void Insert(HashTable &HT, STUDENT x) {
    if((double)(HT.n + 1) / HT.M >= LOAD) return;

    int index = HashFunction(HT, x.MSSV);
    int base_index = index;
    int i = 0;
    while(HT.Table[index].MSSV != EMPTY && HT.Table[index].MSSV != DELETE) {
        index = (base_index + i) % HT.M;
        ++i;
    }
    HT.Table[index] = x;
    HT.n++;
}


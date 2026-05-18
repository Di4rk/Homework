#include "Bo.h"

void Bo::Keu() {
    cout << "Um bo... ";
}

int Bo::SinhCon() {
    return rand() % 4;
}

int Bo::ChoSua() {
    return rand() % 21;
}

int Bo::GetLoai() {
    return 1;
}
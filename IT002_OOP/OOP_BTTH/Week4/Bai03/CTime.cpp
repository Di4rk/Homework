#include "CTime.h"
#include <iomanip>

void CTime::ChuanHoa() {
    long long tongGiay = (long long)h * 3600 + m * 60 + s;

    this->h = tongGiay / 3600;
    this->m = (tongGiay % 3600) / 60;
    this->s = tongGiay % 60;
}

CTime::CTime(int h, int m, int s) : h(h), m(m), s(s) {
    ChuanHoa();
}

CTime CTime::operator+(int giay) const {
    return CTime(this->h, this->m, this->s + giay);
}

CTime CTime::operator-(int giay) const {
    return CTime(this->h, this->m, this->s - giay);
}

CTime& CTime::operator++() {
    this->s++;
    ChuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this; 
    this->s++;
    ChuanHoa();
    return temp; 
}

CTime& CTime::operator--() {
    this->s--;
    ChuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    this->s--;
    ChuanHoa();
    return temp;
}

istream& operator>>(istream& in, CTime& t) {
    cout << "Nhap thoi gian (Gio Phut Giay): ";
    in >> t.h >> t.m >> t.s;
    t.ChuanHoa();
    return in;
}

ostream& operator<<(ostream& out, const CTime& t) {
    out << setfill('0') << setw(2) << t.h << ":"
        << setfill('0') << setw(2) << t.m << ":"
        << setfill('0') << setw(2) << t.s;
    return out;
}
#include "CDate.h"
#include <cmath>

int CDate::daysInMonth(int m, int y) {
	if (m == 2) {
		return (y % 4 == 0 && y % 100 != 0) || (y % 400) == 0 ? 29 : 28;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	return 31;
}

int CDate::toAbsoluteDays(const CDate& d) {
	int y = d.year;
	int m = d.month;
	if (m <= 2) y--;
	int leapYears = y / 4 - y / 100 + y / 400;
	int days = d.year * 365 + d.day + leapYears;
	for (int i = 1; i < m; i++) {
		days += daysInMonth(i, d.year);
	}
	return days;
}

CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {}

CDate CDate::operator+(int n) const {
	CDate result = *this;
	result.day += n;
	while (result.day > daysInMonth(result.month, result.year)) {
		result.day -= daysInMonth(result.month, result.year);
		result.month++;
		if (result.month > 12) {
			result.month = 1;
			result.year++;
		}
	}
	return result;
}

CDate CDate::operator-(int n) const {
	CDate result = *this; 
	result.day -= n;
	while (result.day < 1) {
		result.month--;
		if (result.month < 1) {
			result.month = 12;
			result.year--;
		}
		result.day += daysInMonth(result.month, result.year);
	}
	return result;
}

CDate& CDate::operator++() {
	*this = *this + 1;
	return *this;
}

CDate& CDate::operator--() {
	*this = *this - 1;
	return *this;
}

CDate CDate::operator++(int) {
	CDate temp = *this;
	*this = *this + 1;
	return temp;
}

CDate CDate::operator--(int) {
	CDate temp = *this;
	*this = *this - 1;
	return temp;
}

int CDate::operator-(const CDate& other) const {
	return abs(toAbsoluteDays(*this) - toAbsoluteDays(other));
}

istream& operator>>(istream& is, CDate& d) {
	is >> d.day >> d.month >> d.year;
	return is;
}

ostream & operator<<(ostream& os, const CDate& d) {
	os << (d.day < 10 ? "0" : "") << d.day << "/"
		<< (d.month < 10 ? "0" : "") << d.month << "/"
		<< d.year;
	return os;
}




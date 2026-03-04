
#include <iostream>
using namespace std;

void NhapMang(int *, int);
void XuatMang(int *, int);
void XoaKPhanTuTuViTriP(int *, int &, int, int);

int main() {
    int n; cin >> n;
	int A[n];
	NhapMang(A, n);

	int p, k; cin >> p >> k;
	XoaKPhanTuTuViTriP(A, n, p, k);

	XuatMang(A, n);
	return 0;
}

void NhapMang(int *A, int n)
{
    for(int i=0;i<n;i++)
        cin >> A[i];
}
void XoaKPhanTuTuViTriP(int *A, int &n, int p, int k)
{
    for(int i =p;i<n-k;i++)
        A[i] = A[i+k];
    n=n-k;
}
void XuatMang(int *A, int n)
{
    for (int i=0;i<n;i++)
        cout << A[i] << " ";
}

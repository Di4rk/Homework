
#include <iostream>
using namespace std;

void NhapMang(int *, int);
void XuatMang(int *, int);
void XoaPhanTu(int *, int &, int);


int main() {
    int n; cin >> n;
	int A[n];
	NhapMang(A, n);

	int x; cin >> x;
	XoaPhanTu(A, n, x);

	XuatMang(A, n);
	return 0;
}

void NhapMang(int A[], int n)
{
    for(int i=0;i<n;i++)
        cin >> A[i];
}
void XoaPhanTu(int A[], int &n, int x)
{
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            for (int j = i; j < n - 1; j++)
                A[j] = A[j + 1];
            n--;
            i--;
        }
    }
}

void XuatMang(int A[], int n)
{
    for(int i =0;i<n;i++)
        cout << A[i] << " ";
}

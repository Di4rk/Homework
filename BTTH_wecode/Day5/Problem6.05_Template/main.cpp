
#include <iostream>
using namespace std;

void NhapMang(int *, int);
void XuatMang(int *, int);
void ChenPhanTuXVaoViTriK(int *, int, int, int);


int main() {
    int n; cin >> n;
	int A[n + 1]; // Mảng ban đầu chỉ có n phần tử lát nữa chúng ta sẽ thêm một phần tử vào nên khởi tạo n + 1
	NhapMang(A, n); // Ban đầu chỉ nhập n phần tử

	int x, k; cin >> x >> k;
	ChenPhanTuXVaoViTriK(A, n, x, k);  // Thêm phần tử mới

	XuatMang(A, n + 1); // In ra mảng sau khi đã thêm phần tử mới vào, lúc này có n + 1 phần tử.
	return 0;
}
void NhapMang(int *A, int n)
{
    for(int i=0;i<n;i++)
        cin >> A[i];
}
void ChenPhanTuXVaoViTriK(int *A, int n, int x ,int k)
{
    for(int i=n+1;i>k;i--)
        A[i]=A[i-1];
    A[k]=x;
}
void XuatMang(int *A,int n)
{
    for (int i=0;i<n;i++)
        cout << A[i] << " ";
}

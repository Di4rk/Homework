#include <iostream>
using namespace std;
#define MAX 100
void Nhapmang(int a[MAX], int n)
{
    for(int i=0;i<n;i++)
        cin >> a[i];
}
bool isBenford(int a[MAX],int n)
{
    int dem1 = 0,dem4 = 0;
    for(int i=0;i<n;i++)
    {
        int check = to_string(a[i])[0] - '0';
        if (check == 1) dem1++;
        if (check == 4) dem4++;
    }
    if(dem1 == 3 & dem4==1) return true;
    return false;
}

int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}

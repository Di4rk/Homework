
#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
	int x;
	cin >> x;
	if (x < 1 || x>30)
		cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
	else
	{
		cout << Fibo(x) << endl;
	}
	return 0;
}

int Fibo(int x)
{
    if(x==1 || x== 2) return 1;
    int a=1,b=1,c;
    for(int i=3;i<=x;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

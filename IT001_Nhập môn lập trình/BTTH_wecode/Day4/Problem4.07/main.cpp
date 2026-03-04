#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


float calculate(int n)
{
    if(n==1) return 1;
    return sqrt(n + calculate(n-1));
}


int main()
{
	int n;
	cin >> n;
    cout << setprecision(3) << calculate(n);
}



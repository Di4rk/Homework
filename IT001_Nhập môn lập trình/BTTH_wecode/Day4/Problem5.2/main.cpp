#include <iostream>
#include <iomanip>
using namespace std;
double myabs(double a)
{
   return a < 0 ? -a : a;
}
double hangtua(double x,double a, int k)
{
    if (myabs(a)<=0.00001) return 0.00001;
    double a1 = -a * x * x / ((2*k+2)*(2*k+3));
    return a + hangtua(x, a1, k+1);
}
int main()
{
    float x;
    cin >> x;
    cout << fixed << setprecision(4) << hangtua(x,x,0);

}

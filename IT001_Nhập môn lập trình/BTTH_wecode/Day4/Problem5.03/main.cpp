#include <iostream>
using namespace std;

int largest_input()
{
    int a;
    cin >> a;
    if (a==0) return 0;
    int mx = largest_input();
    return (a>mx ? a : mx);
}

int main(){
	cout << largest_input();
}

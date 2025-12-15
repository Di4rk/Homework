#include <bits/stdc++.h>
int TongChuSo(int a)
{
    int i=0;
    while(a!=0)
    {
        i+=a%10;
        a/=10;
    }
    return i;
}
void input(int &a)
{
    std::cin >> a;
}
    int main() {
    int a;
    input(a);
    std::cout << TongChuSo(a);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long getLength(long long n)
{
    if (n == 0) return 0;
    string s = to_string(n);
    return s.length();
}

long long countDigitsRange(long long n)
{
    if (n == 0) return 0;
    long long count =0;
    long long scale = 1;
    long long digits = 1;
    while (scale <= n)
    {
        long long nextScale = scale *10;
        long long end = min(n, nextScale -1);
        long long numbersInRange = end - scale +1;
        count += (numbersInRange * digits);
        scale = nextScale;
        digits++;
    }
    return count;
}

int main()
{
    long long n;
    cin >> n;
    long long totalCost=1;
    if (n>1)
    {
        totalCost += getLength(n);
    }
    if (n >= 10)
    {
        long long k = (n-1)/10;
        long long sumLengths = countDigitsRange(k);
        totalCost += sumLengths + k;
    }
    cout << totalCost << endl;
    return 0;
}
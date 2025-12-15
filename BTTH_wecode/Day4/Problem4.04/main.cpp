
#include <iostream>
#include <cmath>
using namespace std;
int sum_common_prime(long long m, long long n) {
    long long S = 0;

    for (long long i = 2; i * i <= m; i++) {
        if (m % i == 0 && n % i == 0) {
            S += i;
        }
        while (m % i == 0) m /= i;
    }

    if (m > 1 && n % m == 0) S += m;

    if (S == 0) return -1;
    return S;
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << sum_common_prime(m, n);
}

#include <iostream>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return (!b) ? a : gcd(b, a % b);
}

unsigned long long binom(unsigned long long n, unsigned long long k) {
    if (k > n - k) k = n - k;

    unsigned long long res = 1, i, t;
    for (i = 1; i <= k; i++) {
        t = gcd(res, i);
        res = (res / t) * ((n - i + 1) / (i / t));
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n, k;
        cin >> n >> k;
        cout << binom(n, k) << "\n";
    }
}


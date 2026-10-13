#include <iostream>
#include <vector>
using namespace std;

vector<int> get_primes(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    vector<int> primes;
    if (max_n >= 2) {
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= max_n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= max_n; i += p)
                    is_prime[i] = false;
            }
        }
        for (int p = 2; p <= max_n; p++) {
            if (is_prime[p]) primes.push_back(p);
        }
    }
    return primes;
}

int legandr(int m, int p) {
    int count = 0;
    while (m > 0) {
        count += m / p;
        m /= p;
    }
    return count;
}

void solve(int n, int k) {
    if (n == k || k == 0) cout << 1;

    bool is_first = true;
    vector<int> primes = get_primes(n);
    for (auto p : primes) {
        int power = legandr(n, p) - legandr(k, p) - legandr((n - k), p);

        if (power > 0) {
            if (!is_first) {
                cout << " * ";
            }
            is_first = false;

            if (power == 1) {
                cout << p;
            }
            else {
                cout << p << "^" << power;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned int n, k;
        cin >> n >> k;
        solve(n, k);
        cout << "\n";
    }
}
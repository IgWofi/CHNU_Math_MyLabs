#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInt {
    vector<int> number;

    int compare(const BigInt& data) const {
        if (number.size() != data.number.size())
            return number.size() < data.number.size() ? -1 : 1;

        for (int i = (int)number.size() - 1; i >= 0; i--) {
            if (number[i] != data.number[i])
                return number[i] < data.number[i] ? -1 : 1;
        }
        return 0;
    }
public:
    BigInt(string data) { for (int i = data.length() - 1; i >= 0; i--) number.push_back((int)(data[i] - '0')); }
    BigInt(vector<int> data) { number = data; }
    BigInt(const BigInt& data) { number = data.number; }

    BigInt& operator=(const BigInt& data) { this->number = data.number; return *this; }

    BigInt operator+(const BigInt& data) const {
        vector<int> res;
        int i = 0, j = 0, carry = 0;
        while (i < this->number.size() || j < data.number.size() || carry > 0) {
            int sum = carry;

            if (i < this->number.size()) {
                sum += this->number[i];
                i++;
            }

            if (j < data.number.size()) {
                sum += data.number[j];
                j++;
            }

            carry = sum / 10;

            res.push_back(sum % 10);
        }

        return BigInt(res);
    }

    BigInt operator-(const BigInt& data) const

    {
        vector<int> res;
        int borrow = 0;

        for (size_t i = 0; i < number.size(); i++) {
            int diff = number[i] - borrow;
            if (i < data.number.size()) diff -= data.number[i];

            if (diff < 0) { diff += 10; borrow = 1; }
            else borrow = 0;

            res.push_back(diff);
        }

        while (res.size() > 1 && res.back() == 0) res.pop_back();
        return BigInt(res);
    }

    BigInt operator*(const BigInt& data) const {
        if ((this->number.size() == 1 && this->number[0] == 0) || (data.number.size() == 1 && data.number[0] == 0)) return BigInt("0");

        vector<int> res(this->number.size() + data.number.size(), 0);
        for (int i = 0; i < this->number.size(); i++) {
            int carry = 0;

            for (int j = 0; j < data.number.size(); j++) {
                int current = res[i + j] + this->number[i] * data.number[j] + carry;

                res[i + j] = current % 10;
                carry = current / 10;
            }

            if (carry > 0) {
                res[i + data.number.size()] += carry;
            }
        }

        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }

        return res;
    }

    BigInt divSmall(int d) const {
        vector<int> res(number.size(), 0);
        long long r = 0;

        for (int i = (int)number.size() - 1; i >= 0; i--) {
            long long cur = r * 10 + number[i];
            res[i] = cur / d;
            r = cur % d;
        }

        while (res.size() > 1 && res.back() == 0) res.pop_back();
        return BigInt(vector<int>(res));
    }

    bool operator==(const BigInt& o) const { return compare(o) == 0; }
    bool operator< (const BigInt& o) const { return compare(o) < 0; }
    bool operator>=(const BigInt& o) const { return compare(o) >= 0; }

    void Print() {
        for (int i = this->number.size() - 1; i >= 0; i--) { cout << this->number[i]; }
    }
};

BigInt C(const BigInt& n, int k) {
    BigInt res("1");

    for (int i = 0; i < k; i++) {
        res = res * (n - BigInt(to_string(i)));
        res = res.divSmall(i + 1);
    }

    return res;
}

int main() {
    string x;
    cin >> x;

    BigInt ans(x);
    for (int k = 169; k > 1; k--) {
        BigInt lo(to_string(2 * k));
        BigInt hi(lo);

        while (C(hi, k) < ans) {
            lo = hi;
            hi = hi * BigInt("2");
        }
        while (lo < hi) {
            BigInt m((lo + hi).divSmall(2));
            if (C(m, k) >= ans) hi = m;
            else lo = m + BigInt("1");
        }
        if (C(lo, k) == x) {
            ans = lo;
            break;
        }
    }

    ans.Print();

    return 0;
}

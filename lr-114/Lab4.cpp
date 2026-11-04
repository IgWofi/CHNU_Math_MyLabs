#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int n;
	cin >> n;

	vector<int> arr(n);
	int temp, product = 1;
	unsigned int zero_counter = 0, zero_indx;
	for (unsigned int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
		if (temp != 0) product *= temp;
		else {
			zero_counter++;
			zero_indx = i;
		}

		if (zero_counter > 1) {
			for (unsigned int j = 0; j < n; j++) cout << 0 << " ";
			return 0;
		}
	}

	if (zero_counter > 0) {
		for (unsigned int i = 0; i < zero_indx; i++) cout << 0 << " ";
		cout << product << " ";
		for (unsigned int i = zero_indx + 1; i < n; i++) cout << 0 << " ";
		return 0;
	}
	for (int x : arr) {
		cout << product / x << " ";
	}

	return 0;
}
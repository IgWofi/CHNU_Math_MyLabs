#include <iostream>
#include <string>

using namespace std;

int main() {
	string data; cin >> data;
	
	bool flag = false;
	cout << "\n";
	for (char c: data) {
		if (c == '1') if (flag) cout << '0';
		else {
			flag = true;
			cout << '1';
		}
	}

	return 0;
}
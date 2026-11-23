#include <iostream>
#include <string>

using namespace std;

int main() {
	string data; cin >> data;
	
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0') data[i] = '1';
		else data[i] = '0';
	}

	bool flag = false;
	cout << "\n";
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0' && flag == false) continue;
		flag = true;
		cout << data[i];
	}

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	string data; cin >> data;
	
	bool flag = false;
	cout << "\n";
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '1' && flag == false) continue;
		else if (data[i] == '1' && flag == true) cout << '0';
		else { flag = true; cout << '1'; }
	}

	return 0;
}
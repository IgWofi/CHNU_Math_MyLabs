#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int indx_first_max = 0, indx_last_min = 0, score_of_max = 0, score_of_min = 0, elm;
	cout << "Enter array elements (in the end enter letter): ";
	while (cin >> elm) arr.push_back(elm);

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= arr[indx_last_min]) indx_last_min = i;
		if (arr[i] > arr[indx_first_max]) indx_first_max = i;
	}


	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr[indx_first_max]) score_of_max++;
		if (arr[i] == arr[indx_last_min]) score_of_min++;
	}

	cout << "\n\nIndex of first max: " << indx_first_max;
	cout << "\nIndex of last min: " << indx_last_min;
	if (score_of_max > score_of_min) cout << "\nMore max than min";
	else if(score_of_min > score_of_max) cout << "\nMore min than max";
	else cout << "\nMax and min equally";

	return 0;
}
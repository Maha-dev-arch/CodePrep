#include <iostream>

using namespace std;

//Given following input array, output has to be as follows,
//Input: {0, 1, 2, 4, 5, 6, 8} Output should be : 0->2, 4->6, 8
//Input : {0, 1, 3, 5, 6, 8, 9} Output should be : 0->1, 3, 5->6, 8->9

void printSequence(int* arr, int len) {
	int start = arr[0];
	bool seq = false;

	for (int i = 1; i < len; i++) {
		if (arr[i] != (arr[i - 1] + 1)) {
			if (start != arr[i - 1])
				cout << start << "->" << arr[i - 1] << endl;
			else
				cout << start << endl;
			start = arr[i];
			seq = false;
		}
		else {
			
			/*if (i == len - 1) {
				if(seq)
					cout << start << "->" << arr[i] << endl;
				else
					cout << arr[i]<<endl;
			}*/
			seq = true;
		}

	}
	if (seq)
		cout << start << "->" << arr[len-1] << endl;
	else
		cout << arr[len-1] << endl;

}

//int main() {
//	int arr[] = { 0, 1, 2, 4, 5, 6, 8 };
//	int arr1[] = { 0, 1, 3, 5, 6, 8, 9 };
//	//printSequence(arr, sizeof(arr)/sizeof(arr[0]));
//	printSequence(arr1, sizeof(arr1) / sizeof(arr1[0]));
//	return 0;
//}
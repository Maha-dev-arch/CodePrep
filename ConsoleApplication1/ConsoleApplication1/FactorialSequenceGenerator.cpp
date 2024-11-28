#include <iostream>

using namespace std;

int printFactSequence(int n) {
	int fact;
	fact = (n == 0) ? 1 : n * printFactSequence(n - 1);
	cout << fact << " ";
	return fact;
}

//int main() {
//	int n;
//	cin >> n;
//	printFactSequence(n);
//	return 0;
//}
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//Bubble sort
void sort(int* a, int len) {
	for (int j = len - 1; j >= 1; j--) {
		bool swapHappened = false;
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				swapHappened = true;
				swap(a[i], a[i + 1]);
			}
		}
		if (!swapHappened)
			break;
	}
}

//int main()
//{
//	int a[] = { 90,80,70,60,50,40,30,20,10 };
//	int len = (sizeof(a) / sizeof(a[0]));
//	sort(a, len);
//	for(int i=0; i<len; i++)
//		cout << a[i] <<" ";
//	return 0;
//}
#include <stdio.h>

void merge(int a[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[5], R[5];
	for (int i = 0; i < n1; i++)
		L[i] = a[left+i];
	for (int i = 0; i < n2; i++)
		R[i] = a[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int a[], int left, int right) {
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
//int main()
//{
//	int a[] = { 20,30,10,50,40 };
//	int arrSize = sizeof(a) / sizeof(a[0]);
//
//	mergeSort(a, 0, arrSize - 1);
//	for (int i = 0; i < arrSize; i++)
//		printf("%d ", a[i]);
//}
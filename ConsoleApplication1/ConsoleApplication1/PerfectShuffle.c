#include <stdio.h>
#include <string.h>

//int main()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
//	char shuffled[27] = { '\0' };
//	char temp[27] = { '\0' };
//	int count = 1;
//
//	strcpy_s(temp, 27, arr);
//	while (1) {
//		for (int i = 0; i < 26; i++) {
//			if (i % 2 == 0)
//				shuffled[i] = temp[i / 2];
//			else
//				shuffled[i] = temp[i/2 + 13];
//		}
//		if (strcmp(arr, shuffled) == 0)
//			break;
//		strcpy_s(temp, 27, shuffled);
//		++count;
//	}
//	printf("Number of shuffles needed to get back original: %d", count);
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        if (*a > *b) {
            return 1;
        }
        else if (*a < *b) {
            return 0;
        }
        else {
            a++;
            b++;
        }
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return !(lexicographic_sort(a, b));
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int numOfCharA = strlen(a), numOfCharB = strlen(b);
    char* tempA = (char*) malloc(numOfCharA + 1);
    char* tempB = (char*)malloc(numOfCharB + 1);
    memset(tempA, '\0', numOfCharA + 1);
    memset(tempB, '\0', numOfCharB + 1);

    while (*a != '\0') {
        int i;
        for (i = 0; tempA[i] != '\0'; i++) {
            if (tempA[i] == *a) {
                --numOfCharA;
                break;
            }
        }
        if (tempA[i] == '\0')
            tempA[i] = *a;
        ++a;
    }
    while (*b != '\0') {
        int i;
        for (i = 0; tempB[i] != '\0'; i++) {
            if (tempB[i] == *b) {
                --numOfCharB;
                break;
            }
        }
        if (tempB[i] == '\0')
            tempB[i] = *b;
        ++b;
    }
    if (numOfCharA < numOfCharB) {
        return 0;
    }
    else if (numOfCharA > numOfCharB) {
        return 1;
    }
    else {
        return lexicographic_sort(a, b);
    }
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) < strlen(b))
        return 0;
    else if (strlen(a) > strlen(b))
        return 1;
    else {
        return lexicographic_sort(a, b);
    }
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    char* temp;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) == 1) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }

}


//int main()
//{
//    int n;
//    scanf("%d", &n);
//
//    char** arr;
//    arr = (char**)malloc(n * sizeof(char*));
//
//    for (int i = 0; i < n; i++) {
//        *(arr + i) = (char*) malloc(1024 * sizeof(char));
//        scanf("%s", *(arr + i));
//        *(arr + i) = (char*) realloc(*(arr + i), strlen(*(arr + i)) + 1);
//    }
//
//    string_sort(arr, n, lexicographic_sort);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, lexicographic_sort_reverse);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, sort_by_length);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, sort_by_number_of_distinct_characters);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//}
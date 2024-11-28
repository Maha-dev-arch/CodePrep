#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);


/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

 /*
  * To return the integer array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * int* return_integer_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static int a[5] = {1, 2, 3, 4, 5};
  *
  *     return a;
  * }
  *
  * int* return_integer_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     int *a = malloc(5 * sizeof(int));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = i + 1;
  *     }
  *
  *     return a;
  * }
  *
  */
int maxStack[10000] = { 0 };

int* getMax(int operations_count, char** operations, int* result_count) {
    int** stack = calloc(10, sizeof(int*));
    int top = 0;
    
    *result_count = 0;
    
    for (int i = 0; i < operations_count; i++) {
        char* next_token = NULL;
        int* a = NULL;
        int max = 0;

        switch(*operations[i]) {
        case '1':
            stack[top] = (int*)malloc(sizeof(int));
            char* c = strtok_s(operations[i], " ", &next_token);
            *stack[top] = atoi(strtok_s(NULL, " ", &next_token));
            top++;
            break;
        case '2':
            free(stack[top]);
            top--;
            break;

        case '3':
            max = 0;
            for (int j = 0; j <= top; j++) {
                if (stack[j] && *stack[j] > max)
                    max = *stack[j];
            }
            maxStack[(*result_count)++] = max;
            break;
        }
    }
    return maxStack;
}

//int main() {
//    int resCount = 0;
//    int* maxArray;
//
//    char** operArray = calloc(10, sizeof(char*));
//
//    for (int i = 0; i < 10; i++) {
//        char* operations = calloc(10 , sizeof(char));
//        operArray[i] = operations;
//    }
//    strcpy_s(operArray[0], 9, "1 97");
//    strcpy_s(operArray[1], 9, "1 98");
//    strcpy_s(operArray[2], 9, "3");
//
//    //char* operations[] = { "1 97" };
//    maxArray = getMax(3, operArray, &resCount);
//
//    for (int i = 0; i < resCount; i++) {
//        printf("%d ", maxArray[i]);
//    }
//    return 0;
//}
//int main()
//{
//    FILE* fptr;
//    char* pValue;
//    size_t len;
//
//    fopen_s(&fptr, _dupenv_s(&pValue, &len, "OUTPUT_PATH"), "w");
//
//    int n = parse_int(ltrim(rtrim(readline())));
//
//    char** ops = malloc(n * sizeof(char*));
//
//    for (int i = 0; i < n; i++) {
//        char* ops_item = readline();
//
//        *(ops + i) = ops_item;
//    }
//
//    int res_count;
//    int* res = getMax(n, ops, &res_count);
//
//    for (int i = 0; i < res_count; i++) {
//        fprintf(fptr, "%d", *(res + i));
//
//        if (i != res_count - 1) {
//            fprintf(fptr, "\n");
//        }
//    }
//
//    fprintf(fptr, "\n");
//
//    fclose(fptr);
//
//    return 0;
//}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    }
    else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        }
        else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

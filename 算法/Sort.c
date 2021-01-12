#include "Sort.h"


void Print(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertSort(int arr[], int length) {
    printf("================================================\n");
    printf("排序前： \n");
    Print(arr, length);

    for (int i = 2; i < length; i++) {
        if (arr[i] < arr[i - 1]) {
            arr[0] = arr[i];    // 哨兵
            arr[i] = arr[i - 1];// 将arr[i]的前一项后移
            int j;
            for (j = i - 2; arr[0] < arr[j]; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j + 1] = arr[0];
        }
    }

    printf("直接插入排序后： \n");
    Print(arr, length);
}


void ShellSort(int arr[], int length) {
    printf("================================================\n");
    printf("排序前： \n");
    Print(arr, length);


    printf("直接插入排序后： \n");
    Print(arr, length);
}
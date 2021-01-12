#include "Search.h"
#include "Sort.h"
#define length 11

int main() {
    // -----------------搜索算法---------------------------------------
    int arr[length] = {1, 2, 3, 5, 6, 7, 12, 14, 22, 43, 77};
    int target = 1;

    BinarySearch(arr, length, target);


    // -----------------排序算法---------------------------------------
    // int arr[length] = {0, 1, 3, 5, 7, 2, 8, 4, 11, 45, 15};
    // InsertSort(arr, length);

    return 0;
}
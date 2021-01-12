#include "Search.h"

void BinarySearch(int arr[], int length, int target) {
    int index = 1;
    int low = 0;
    int high = length - 1;
    int mid = 0;

    while (high >= low) {
        mid = (high + low) / 2;
        if (arr[mid] == target) {
            index = mid;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (index != -1) {
        printf("折半查找结果: arr[%d] = %d\n", index, target);
        return;
    }
    printf("表中没有元素%d\n", target);
}
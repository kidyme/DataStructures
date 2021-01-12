#include <stdio.h>
// 全部序列都最终都排序为递增序列
// 全部序列的第一个即arr[0]不放数据，置0，长度从arr[1]开始计

// 打印数组
void Print(int arr[], int length);

// 直接插入排序
void InsertSort(int arr[], int length);

// 希尔排序
void ShellSort(int arr[], int length);

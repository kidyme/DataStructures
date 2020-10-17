//
// Created by kidyme on 2020/10/16.
//

#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100     // 顺序线性表存储空间的初始值 单位为sizeof(int)
#define LIST_SIZE_INCREAMENT 10// 顺序线性表存储空间的增量 单位为sizeof(int)

#define OVERFLOW 1// 分配内存失败，溢出
#define ERROR 0   // 失败
#define SUCCESS 1 // 成功

// int型顺序线性表
typedef struct {
    int *elem; // 顺序线性表的地址，即第一个元素的地址
    int length;// 顺序线性表的长度
    int size;  // 顺序线性表的可用的存储空间 单位为sizeof(int)
} SqList;

void InitList(SqList *list);
// 初始化顺序线性表list

int InsertList(SqList *list, int index, int value);
// 在顺序线性表list的第index个位置插入值value

int DeleteList(SqList *list, int index, int *value);
// 删除顺序线性表list的第index个元素，并将其值用value返回

void SortList(SqList *list);
// 冒泡排序 递增排序
void MergeList(SqList *list_1, SqList *list_2, SqList *new_list);
// 合并

void PrintList(SqList *list);
// 打印顺序线性表
#endif//SQLIST_H

//
// Created by kidyme on 2020/10/17.
//

#ifndef PRAC_C_LINKEDLIST_H
#define PRAC_C_LINKEDLIST_H
// 不含头节点的单链表

#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 1// 分配内存失败，溢出
#define ERROR 0   // 失败
#define SUCCESS 1 // 成功

typedef struct Node {
    int data;         // 数据域
    struct Node *next;// 指针域
} Node;
typedef struct Node *LkList;
// 头指针

int GetLength(LkList list);
// 计算链表的长度

int QueryByIndex(LkList list, int index, int *value);
// 查找链表list第index个元素, 并将该元素的值用value返回, 若成功函数返回值为1, 失败则返回0

int QueryByValue(LkList list, int value, int *index);
// 查找链表list中值为value的第一个元素, 并将该元素的序号用index返回, 若成功函数返回值为1, 失败则返回0

LkList InsertList(LkList list, int index, int value);
// 在链表list的第index个位置插入值value

LkList DeleteList(LkList list, int index, int *value);
// 删除链表list的第index个元素， 并将该元素的值用value返回

LkList MergerList(LkList list_1, LkList list_2);
// 合并
// 将两个递增链表合并成第三个递增链表
// 可保留两条原链表

void PrintList(LkList list);
// 打印链表

#endif//PRAC_C_LINKEDLIST_H

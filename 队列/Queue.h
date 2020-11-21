//
// Created by kidyme on 2020/11/19.
// 链式队列
// 有头节点
//

#ifndef PRAC_C_QUEUE_H
#define PRAC_C_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 1
#define SUCCESS 1
#define ERROR 0
#define EMPTY 1
#define NOT_EMPTY 0

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

typedef int (*func) (Node*);

void InitQueue(Queue *queue);
// 构造队列

void DestroyQueue(Queue *queue);
// 销毁队列

void ClearQueue(Queue *queue);
// 清空队列

int IsEmpty(Queue *queue);
// 判断队列是否为空

int GetLength(Queue *queue);
// 获取队列长度

int GetHead(Queue *queue, int *value);
// 获取队首元素，值用value返回，函数返回状态

int GetTail(Queue *queue, int *value);
// 获取队尾元素，值用value返回，函数返回状态

void EnQueue(Queue *queue, int value);
// 入队

int DeQueue(Queue *queue, int* value);
// 出队，函数返回状态，若队列为空则返回ERROR，value返回删除的值

int TraverseQueue(Queue* queue, func operation);
// 遍历队列并对每个元素进行operation()操作，一旦operation()返回ERROR，函数返回ERROR

int PrintQueue(Node* node);
// 打印队列

#endif//PRAC_C_QUEUE_H

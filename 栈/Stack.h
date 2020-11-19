//
// Created by kidyme on 2020/10/21.
//

#ifndef PRAC_C_STACK_H
#define PRAC_C_STACK_H

#include <stdio.h>
#include <stdlib.h>
// 顺序栈
#define STACK_INIT_SIZE 10// 栈的初始存储空间
#define STACK_INCREMENT 10 // 存储空间的增量
#define OVERFLOW 1
#define SUCCESS 1
#define ERROR 0
#define EMPTY 1
#define NOT_EMPTY 0
#define NOT_EXIST -1

typedef struct {
    int *base;// 栈底指针，在栈的构造之前和销毁之后都为NULL
    int *top; // 栈顶指针，在栈的构造之前和销毁之后都为NULL，空栈时等于base
    int size; //栈的可用存储空间，单位为sizeof(int)
} SqStack, *Pointer_SqStack;

void InitStack(Pointer_SqStack stack);
// 初始化栈

int IsEmpty(Pointer_SqStack stack);
// 判断栈是否为空

int DestroyStack(Pointer_SqStack stack);
// 销毁栈

int ClearStack(Pointer_SqStack stack);
// 清空栈

int GetLength(Pointer_SqStack stack);
// 获取栈的长度

int Push(Pointer_SqStack stack, int value);
// 压入栈

int Pop(Pointer_SqStack stack, int *value);
// 弹出栈

int PrintStack(Pointer_SqStack stack);
// 打印栈

#endif//PRAC_C_STACK_H

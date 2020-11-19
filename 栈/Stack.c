//
// Created by kidyme on 2020/10/21.
//

#include "Stack.h"


void InitStack(Pointer_SqStack stack) {
    if (stack->base) {
        DestroyStack(stack);// 如果栈已存在，则先销毁
    }
    stack->base = (int *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!stack->base) {
        exit(OVERFLOW);
    }
    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
}


int IsEmpty(Pointer_SqStack stack) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }
    if (stack->top == stack->base) {
        return EMPTY;
    }
    else {
        return NOT_EMPTY;
    }
}

int DestroyStack(Pointer_SqStack stack) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }
    free(stack->base);
    stack->base = NULL;
    stack->top = stack->base;
    stack->size = 0;
    return SUCCESS;
}

int ClearStack(Pointer_SqStack stack) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }
    stack->top = stack->base;
    return SUCCESS;
}

int GetLength(Pointer_SqStack stack) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }
    return (int) (((unsigned long) stack->top - (unsigned long) stack->base) / sizeof(int));
}

int Push(Pointer_SqStack stack, int value) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }

    // 若存储空间不够则重新分配
    if (GetLength(stack) >= stack->size) {
        printf("重新分配栈的存储空间\n");
        int *new_base = (int *) realloc(stack->base, (stack->size + STACK_INCREMENT) * sizeof(int));
        if (!new_base) {
            exit(OVERFLOW);
        }
        stack->base = new_base;
        stack->top = stack->base + stack->size;
        stack->size += STACK_INCREMENT;
    }

    *stack->top = value;
    stack->top++;

    return SUCCESS;
}

int Pop(Pointer_SqStack stack, int *value) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }

    if (IsEmpty(stack)) {
        printf("栈为空栈，无元素可弹出栈\n");
        return ERROR;// 空栈
    }

    *value = *(stack->top - 1);
    stack->top--;

    return SUCCESS;
}

int PrintStack(Pointer_SqStack stack) {
    if (stack->base == NULL) {
        printf("栈不存在\n");
        return NOT_EXIST;// 栈不存在
    }

    for (int *ptr_stack = stack->base; ptr_stack < stack->top; ++ptr_stack) {
        if (ptr_stack != stack->base) {
            printf(" ");
        }
        printf("%d", *ptr_stack);
    }
    printf("\n");
    return SUCCESS;
}

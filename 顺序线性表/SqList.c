//
// Created by kidyme on 2020/10/16.
//

#include "SqList.h"

void InitList(SqList *list) {
    list->elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
    if (!list->elem) {
        exit(OVERFLOW);
    }
    list->length = 0;
    list->size = LIST_INIT_SIZE;
}

int InsertList(SqList *list, int index, int value) {
    if (index < 1 || index > list->length + 1) {
        return ERROR;// index不合法，返回0
    }
    if (list->length >= list->size) {// 为顺序线性表重新分配内存
        int *new_base = (int *) realloc(list->elem, (list->size + LIST_SIZE_INCREAMENT) * sizeof(int));
        if (!new_base) {
            exit(OVERFLOW);// 分配内存失败，程序非正常退出并返回1
        }
        list->elem = new_base;
        list->size += LIST_SIZE_INCREAMENT;
    }

    int *loc_insert_elem = list->elem + index - 1;     // loc_insert_elem为要插入的元素的地址
    int *loc_move_elem = list->elem + list->length - 1;// loc_move_elem为目前正在移动的元素的地址
    for (; loc_move_elem >= loc_insert_elem; loc_move_elem--) {
        *(loc_move_elem + 1) = *loc_move_elem;
    }
    *loc_insert_elem = value;// 赋值
    list->length++;
    return SUCCESS;// 插入成功，返回1
}

int DeleteList(SqList *list, int index, int *value) {
    if (index < 1 || index > list->length) {
        return ERROR;
    }
    *value = list->elem[index - 1];                    // 将list的第index个元素的值保存在value中
    int *loc_move_elem = list->elem + index;           // loc_move_elem为目前正在移动的元素的地址
    int *loc_last_elem = list->elem + list->length - 1;// loc_last_elem为表尾元素的地址
    for (; loc_move_elem <= loc_last_elem; loc_move_elem++) {
        *(loc_move_elem - 1) = *loc_move_elem;
    }
    list->length--;
    return SUCCESS;
}

void SortList(SqList *list) {
    int temp;
    for (int i = 0; i < list->length - 1; ++i) {
        for (int j = 0; j < list->length - i - 1; ++j) {
            if (list->elem[j] > list->elem[j + 1]) {
                temp = list->elem[j];
                list->elem[j] = list->elem[j + 1];
                list->elem[j + 1] = temp;
            }
        }
    }
}

void MergeList(SqList *list_1, SqList *list_2, SqList *new_list) {
    new_list->length = list_1->length + list_2->length;
    new_list->size = list_1->size + list_2->size;
    new_list->elem = (int *) malloc(new_list->size * sizeof(int));
    if (!new_list->elem) {
        exit(OVERFLOW);// 分配内存失败，程序非正常退出并返回1
    }

    int *loc_comp_list_1_elem = list_1->elem;                // 线性表list_1中正在进行比对的的元素的地址
    int *loc_comp_list_2_elem = list_2->elem;                // 线性表list_2中正在进行比对的的元素的地址
    int *loc_list_1_last = list_1->elem + list_1->length - 1;// 线性表list_1中最后一个元素的地址
    int *loc_list_2_last = list_2->elem + list_2->length - 1;// 线性表list_2中最后一个元素的地址
    int *loc_put_new_list_elem = new_list->elem;             // 合并后的新线性表new_list中正要填入的地址

    while ((loc_comp_list_1_elem <= loc_list_1_last) && (loc_comp_list_2_elem <= loc_list_2_last)) {
        if (*loc_comp_list_1_elem <= *loc_comp_list_2_elem) {
            *loc_put_new_list_elem = *loc_comp_list_1_elem;
            loc_put_new_list_elem++;
            loc_comp_list_1_elem++;
        }
        else {
            *loc_put_new_list_elem = *loc_comp_list_2_elem;
            loc_put_new_list_elem++;
            loc_comp_list_2_elem++;
        }
    }
    while (loc_comp_list_1_elem <= loc_list_1_last) {
        *loc_put_new_list_elem = *loc_comp_list_1_elem;
        loc_put_new_list_elem++;
        loc_comp_list_1_elem++;
    }
    while (loc_comp_list_2_elem <= loc_list_2_last) {
        *loc_put_new_list_elem = *loc_comp_list_2_elem;
        loc_put_new_list_elem++;
        loc_comp_list_2_elem++;
    }
}

void PrintList(SqList *list) {
    for (int i = 0; i < list->length; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%d", list->elem[i]);
    }
    printf("\n");
}


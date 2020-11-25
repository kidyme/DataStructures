//
// Created by kidyme on 2020/10/17.
//

#include "LinkedList.h"

int GetLength(LkList list) {
    int length = 0;
    LkList move_node = list;// move_node指向链表第一个节点

    while (move_node) {
        length++;
        move_node = move_node->next;
    }

    return length;
}

int QueryByIndex(LkList list, int index, int *value) {
    if (index <= 0) {
        printf("所查序号小于0, 非法\n");
        *value = 0;
        return ERROR;// index的值不合法
    }
    if (!list) {
        printf("链表为空, 非法\n");
        *value = 0;
        return ERROR;// 链表为空
    }

    LkList move_node = list;// 指向链表的第一个节点, 顺着链表前移直至序号为index
    int index_comp_elem = 1;// 正在与index进行比对的元素序号

    while (index_comp_elem != index) {
        if (!move_node->next) {
            printf("所查序号大于链表的长度, 非法\n");
            *value = 0;
            return ERROR;// index值不合法(大于链表长度)
        }
        index_comp_elem++;
        move_node = move_node->next;
    }

    *value = move_node->data;
    return SUCCESS;
}


int QueryByValue(LkList list, int value, int *index) {
    if (!list) {
        printf("链表为空, 非法\n");
        *index = 0;
        return ERROR;// 链表为空
    }

    int move_index = 1;     // 第一个元素的序号
    LkList move_node = list;// 指向链表第一个节点

    while (move_node) {
        if (value == move_node->data) {
            *index = move_index;
            return SUCCESS;
        }

        move_index++;
        move_node = move_node->next;
    }

    *index = 0;
    printf("未找到\n");
    return ERROR;
}

LkList InsertList(LkList list, int index, int value) {
    if (index <= 0) {
        printf("插入位置的序号小于0, 非法\n");
        return NULL;// index的值不合法
    }
    if (index > GetLength(list) + 1) {
        printf("插入位置的序号大于表长加1，非法\n");
        return NULL;// index的值不合法
    }

    // 添加第一个的情况
    if (index == 1) {
        LkList new_node = (LkList) malloc(sizeof(LkList));
        if (!new_node) {
            exit(OVERFLOW);
        }

        new_node->next = list;
        list = new_node;
        new_node->data = value;
        return list;
    }

    int move_index = 1;     // 第一个元素的序号
    LkList move_node = list;// 指向链表第一个节点

    while (move_index != index - 1) {
        move_index++;
        move_node = move_node->next;
    }
    // 使move_node指向第index-1个元素

    LkList new_node = (LkList) malloc(sizeof(LkList));

    new_node->next = move_node->next;
    move_node->next = new_node;
    new_node->data = value;
    return list;
}

LkList DeleteList(LkList list, int index, int *value) {
    if (index <= 0) {
        printf("插入位置的序号小于0, 非法\n");
        return NULL;// index的值不合法
    }
    if (index > GetLength(list)) {
        printf("插入位置的序号大于表长，非法\n");
        return NULL;// index的值不合法
    }

    // 删除第1个元素的情况
    if (index == 1) {
        LkList delete_node = list;
        list = list->next;

        *value = delete_node->data;
        free(delete_node);
        return list;
    }

    int move_index = 1;     // 第一个元素的序号
    LkList move_node = list;// 指向链表第一个节点

    while (move_index != index - 1) {
        move_index++;
        move_node = move_node->next;
    }
    // 使move_node指向第index-1个元素

    LkList delete_node = move_node->next;// 指向要删除的元素
    move_node->next = delete_node->next;

    *value = delete_node->data;
    free(delete_node);

    return list;
}

LkList MergerList(LkList list_1, LkList list_2) {
    LkList new_list = NULL;

    LkList list_1_move_node = list_1;// 指向list_1的第一个节点
    LkList list_2_move_node = list_2;// 指向list_1的第一个节点

    if (list_1_move_node->data < list_2_move_node->data) {
        new_list = InsertList(new_list, 1, list_1_move_node->data);
        // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
        list_1_move_node = list_1_move_node->next;
    }
    else {
        new_list = InsertList(new_list, 1, list_2_move_node->data);
        // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
        list_2_move_node = list_2_move_node->next;
    }

    LkList new_list_point_node = new_list;
    /*
    链表不为空，new_list_point_node的值等于倒数第二个元素的next或者链表头指针(链表仅有1个元素时)，
    即指向倒数第一个元素，作为参数传入insert函数
    再将insert的第二个参数index传入2，用new_list_point_node接收函数返回值，
    即，将倒数第二个元素的next看作头指针，然后向该头指针所领的链表(含一个元素)的第二个位置也就是最后一个位置插入值
    链表为空的时候需执行另外的代码是因为，空链表没有元素
    复杂度为O(1)
     */

    while (list_1_move_node && list_2_move_node) {
        if (list_1_move_node->data < list_2_move_node->data) {
            new_list_point_node = InsertList(new_list_point_node, 2, list_1_move_node->data);
            // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
            new_list_point_node = new_list_point_node->next;
            list_1_move_node = list_1_move_node->next;
        }
        else {
            new_list_point_node = InsertList(new_list_point_node, 2, list_2_move_node->data);
            // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
            new_list_point_node = new_list_point_node->next;
            list_2_move_node = list_2_move_node->next;
        }
    }
    while (list_1_move_node) {
        new_list_point_node = InsertList(new_list_point_node, 2, list_1_move_node->data);
        // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
        new_list_point_node = new_list_point_node->next;
        list_1_move_node = list_1_move_node->next;
    }

    while (list_2_move_node) {
        new_list_point_node = InsertList(new_list_point_node, 2, list_2_move_node->data);
        // 将new_list当前要插入的节点地址传入Insert函数，返回插入后节点的地址
        new_list_point_node = new_list_point_node->next;
        list_2_move_node = list_2_move_node->next;
    }

    return new_list;
}

void PrintList(LkList list) {
    int i = 0;
    while (list) {
        if (i) {
            printf(" ");
        }
        printf("%d", list->data);
        list = list->next;
        i++;
    }
    printf("\n");
}
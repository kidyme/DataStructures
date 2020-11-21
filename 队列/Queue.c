//
// Created by kidyme on 2020/11/19.
//

#include "Queue.h"

void InitQueue(Queue *queue) {
    queue->front = (Node *) malloc(sizeof(Node));
    if (!queue->front) {
        exit(OVERFLOW);
    }
    queue->rear = queue->front;
    queue->front->data = 0;
    queue->front->next = NULL;
    printf("队列已初始化\n");
}

void DestroyQueue(Queue *queue) {
    while (queue->front) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
    printf("队列已销毁\n");
}

void ClearQueue(Queue *queue) {
    Node *head = queue->front;
    queue->front = queue->front->next;
    while (queue->front) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
    head->next = NULL;
    queue->front = head;
    queue->rear = queue->front;
    printf("队列已清空\n");
}

int IsEmpty(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("队列为空\n");
        return EMPTY;
    }
    else {
        return NOT_EMPTY;
    }
}

int GetLength(Queue *queue) {
    return queue->front->data;// 用头节点来存储队列的长度信息
}

int GetHead(Queue *queue, int *value) {
    if (IsEmpty(queue)) {
        return ERROR;
    }

    *value = queue->front->next->data;
    return SUCCESS;
}

int GetTail(Queue *queue, int *value) {
    if (IsEmpty(queue)) {
        return ERROR;
    }

    *value = queue->rear->data;
    return SUCCESS;
}

void EnQueue(Queue *queue, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        exit(OVERFLOW);
    }
    new_node->data = value;
    new_node->next = NULL;

    queue->rear->next = new_node;
    queue->rear = new_node;
    queue->front->data++;
}

int DeQueue(Queue *queue, int *value) {
    if (IsEmpty(queue)) {
        return ERROR;
    }

    Node *first_node = queue->front->next;
    queue->front->next = first_node->next;

    *value = first_node->data;
    free(first_node);
    queue->front->data--;

    return SUCCESS;
}

int TraverseQueue(Queue *queue, func operation) {
    if (IsEmpty(queue)) {
        return ERROR;
    }

    Node *move_node = queue->front->next;
    while (move_node) {
        if (!operation(move_node)) {
            return ERROR;
        }
        move_node = move_node->next;
    }
    printf("\n");

    return SUCCESS;
}

int PrintQueue(Node *node) {
    printf("%d ", node->data);
    return SUCCESS;
}

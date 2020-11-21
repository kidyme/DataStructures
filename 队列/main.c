// 测试代码
#include "Queue.h"

int main() {
    printf("Start\n");

    Queue *queue = (Queue *) malloc(sizeof(Queue));
    InitQueue(queue);
    TraverseQueue(queue,PrintQueue);
    EnQueue(queue,1);
    EnQueue(queue,2);
    EnQueue(queue,3);
    EnQueue(queue,4);
    EnQueue(queue,5);
    printf("队列长度为%d\n",GetLength(queue));
    TraverseQueue(queue,PrintQueue);

    int v;
    DeQueue(queue,&v);
    printf("出队：%d\n",v);
    TraverseQueue(queue,PrintQueue);
    printf("队列长度为%d\n",GetLength(queue));

    DeQueue(queue,&v);
    printf("出队：%d\n",v);
    TraverseQueue(queue,PrintQueue);
    printf("队列长度为%d\n",GetLength(queue));

    DeQueue(queue,&v);
    printf("出队：%d\n",v);
    printf("队列长度为%d\n",GetLength(queue));
    TraverseQueue(queue,PrintQueue);
    ClearQueue(queue);
    TraverseQueue(queue,PrintQueue);
    DestroyQueue(queue);

    return 0;
}

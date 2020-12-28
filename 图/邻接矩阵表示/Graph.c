//
// Created by kidyme on 2020/12/2.
//

#include "Graph.h"

void PrintAdjacencyMatrix(GraphPtr graph) {
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            printf("%d ", graph->arcs[i][j].adj);
        }
        printf("\n");
    }
}

void BreadthFirstSearch(GraphPtr graph) {
    printf("广度优先搜索: ");

    QueuePtr assist_queue = InitQueue(graph->vertex_num + 1);
    int assist_array[graph->vertex_num + 1];
    // 初始化辅助数组
    for (int i = 1; i <= graph->vertex_num; ++i) {
        assist_array[i] = 0;
    }

    for (int i = 1; i <= graph->vertex_num; ++i) {
        if (!assist_array[i]) {
            EnQueue(assist_queue, graph->vertexes[i]);// 若某顶点未被访问，则将其入队
            assist_array[i] = 1;
            while (!IsEmpty(assist_queue)) {
                char tmp;
                int tmp_index;
                int next;
                DeQueue(assist_queue, &tmp);// 出队访问，并将与其有边的点依次入队
                printf("%c ", tmp);
                LocateVertex(graph, tmp, &tmp_index);

                while ((next = GetNextVertex(graph, tmp_index, assist_array))) {
                    EnQueue(assist_queue, graph->vertexes[next]);
                    assist_array[next] = 1;
                }
            }
        }
    }
    printf("\n");
}

void DepthFirstSearch(GraphPtr graph) {
    printf("深度优先搜索: ");

    int assist_array[graph->vertex_num + 1];
    // 初始化辅助数组
    for (int i = 1; i <= graph->vertex_num; ++i) {
        assist_array[i] = 0;
    }

    for (int i = 1; i <= graph->vertex_num; ++i) {
        if (!assist_array[i]) {
            DFS(graph, i, assist_array);
        }
    }
    printf("\n");
}

void DFS(GraphPtr graph, int move_vertex, int assist_array[]) {
    printf("%c ", graph->vertexes[move_vertex]);
    assist_array[move_vertex] = 1;

    int next = GetNextVertex(graph, move_vertex, assist_array);
    while (next) {
        DFS(graph, next, assist_array);
        next = GetNextVertex(graph, move_vertex, assist_array);
    }
}

int GetNextVertex(GraphPtr graph, int vertex, int assist_array[]) {
    for (int col = 1; col <= graph->vertex_num; ++col) {
        // 顶点vertex到顶点col有边 且 辅助数组中顶点col未被访问
        if (graph->arcs[vertex][col].adj && !assist_array[col]) {
            return col;
        }
    }
    return 0;
}

// 初始化队列
QueuePtr InitQueue(int length) {
    QueuePtr queue = (QueuePtr) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    queue->max_length = length;
    queue->length = 0;

    return queue;
}

// 判断队是否为空
int IsEmpty(QueuePtr queue) {
    return (queue->length == 0);
}

// 判断队是否已满
int IsFull(QueuePtr queue) {
    return (queue->length == queue->max_length);
}

// 入队
void EnQueue(QueuePtr queue, char value) {
    if (IsFull(queue)) {
        printf("队满，出错\n");
        return;
    }

    queue->length++;
    queue->rear++;
    queue->data[queue->rear] = value;
}

// 出队
void DeQueue(QueuePtr queue, char *value) {
    if (IsEmpty(queue)) {
        printf("队空，出错\n");
    }

    queue->length--;
    *value = queue->data[queue->front + 1];
    queue->front++;
}

void PrintQueue(QueuePtr queue) {
    for (int i = (queue->front + 1); i <= queue->rear; ++i) {
        printf("%c ", queue->data[i]);
    }
    printf("\n");
}

void LocateVertex(GraphPtr graph, char vertex, int *index) {
    int tmp = 1;
    for (; tmp < MAX_VERTEX_NUM; ++tmp) {
        if (vertex == graph->vertexes[tmp]) {
            *index = tmp;
        }
    }
}

int CreateGraph(GraphPtr graph, GraphKind kind) {
    printf("请输入图的顶点数: ");
    scanf("%d", &graph->vertex_num);
    fflush(stdin);
    printf("请输入图的边数: ");
    scanf("%d", &graph->edge_num);
    fflush(stdin);

    switch (kind) {
        case DG:
            CreateDGGraph(graph);
            break;
        case DN:
            CreateDNGraph(graph);
            break;
        case UDG:
            CreateUDGGraph(graph);
            break;
        case UDN:
            CreateUDNGraph(graph);
            break;
        default:
            return ERROR;
    }

    return SUCCESS;
}

int CreateDGGraph(GraphPtr graph) {
    // 输入顶点集合
    for (int i = 1; i <= graph->vertex_num; ++i) {
        printf("请输入第%d个顶点: ", i);
        scanf("%c", &graph->vertexes[i]);
        fflush(stdin);
    }

    // 初始化邻接矩阵
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            graph->arcs[i][j].adj = 0;
            graph->arcs[i][j].info = NULL;
        }
    }

    // 赋值邻接矩阵
    for (int i = 1; i <= graph->edge_num; ++i) {
        char start_vex, end_vex;
        int row = 0, col = 0;

        printf("请输入第%d条边的起点和终点: ", i);
        scanf("%c %c", &start_vex, &end_vex);
        fflush(stdin);

        LocateVertex(graph, start_vex, &row);
        LocateVertex(graph, end_vex, &col);

        while (row == 0) {
            printf("起点不存在!\n");
            printf("请重新输入第%d条边的起点: ", i);
            scanf("%c", &start_vex);
            fflush(stdin);
            LocateVertex(graph, start_vex, &row);
        }
        while (col == 0) {
            printf("终点不存在!\n");
            printf("请重新输入第%d条边的终点: ", i);
            scanf("%c", &end_vex);
            fflush(stdin);
            LocateVertex(graph, end_vex, &col);
        }

        graph->arcs[row][col].adj = 1;
    }


    return SUCCESS;
}

int CreateDNGraph(GraphPtr graph) {
    // 输入顶点集合
    for (int i = 1; i <= graph->vertex_num; ++i) {
        printf("请输入第%d个顶点: ", i);
        scanf("%c", &graph->vertexes[i]);
        fflush(stdin);
    }

    // 初始化邻接矩阵
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            graph->arcs[i][j].adj = 0;
            graph->arcs[i][j].info = NULL;
        }
    }

    // 赋值邻接矩阵
    for (int i = 1; i <= graph->edge_num; ++i) {
        char start_vex, end_vex;
        int row = 0, col = 0;

        printf("请输入第%d条边的起点和终点: ", i);
        scanf("%c %c", &start_vex, &end_vex);
        fflush(stdin);

        LocateVertex(graph, start_vex, &row);
        LocateVertex(graph, end_vex, &col);

        while (row == 0) {
            printf("起点不存在!\n");
            printf("请重新输入第%d条边的起点: ", i);
            scanf("%c", &start_vex);
            fflush(stdin);
            LocateVertex(graph, start_vex, &row);
        }
        while (col == 0) {
            printf("终点不存在!\n");
            printf("请重新输入第%d条边的终点: ", i);
            scanf("%c", &end_vex);
            fflush(stdin);
            LocateVertex(graph, end_vex, &col);
        }

        printf("请输入第%d条边的权值: ", i);
        int weight = 0;
        scanf("%d", &weight);
        fflush(stdin);

        graph->arcs[row][col].adj = weight;
    }


    return SUCCESS;
}

int CreateUDGGraph(GraphPtr graph) {
    // 输入顶点集合
    for (int i = 1; i <= graph->vertex_num; ++i) {
        printf("请输入第%d个顶点: ", i);
        scanf("%c", &graph->vertexes[i]);
        fflush(stdin);
    }

    // 初始化邻接矩阵
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            graph->arcs[i][j].adj = 0;
            graph->arcs[i][j].info = NULL;
        }
    }

    // 赋值邻接矩阵
    for (int i = 1; i <= graph->edge_num; ++i) {
        char start_vex, end_vex;
        int row = 0, col = 0;

        printf("请输入第%d条边的两个点: ", i);
        scanf("%c %c", &start_vex, &end_vex);
        fflush(stdin);

        LocateVertex(graph, start_vex, &row);
        LocateVertex(graph, end_vex, &col);

        while (row == 0) {
            printf("第一个点不存在!\n");
            printf("请重新输入第%d条边的第一个点: ", i);
            scanf("%c", &start_vex);
            fflush(stdin);
            LocateVertex(graph, start_vex, &row);
        }
        while (col == 0) {
            printf("第二个点不存在!\n");
            printf("请重新输入第%d条边的第二个点: ", i);
            scanf("%c", &end_vex);
            fflush(stdin);
            LocateVertex(graph, end_vex, &col);
        }
        graph->arcs[row][col].adj = 1;
        graph->arcs[col][row].adj = 1;
    }


    return SUCCESS;
}


int CreateUDNGraph(GraphPtr graph) {

    // 输入顶点集合
    for (int i = 1; i <= graph->vertex_num; ++i) {
        printf("请输入第%d个顶点: ", i);
        scanf("%c", &graph->vertexes[i]);
        fflush(stdin);
    }

    // 初始化邻接矩阵
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            graph->arcs[i][j].adj = 0;
            graph->arcs[i][j].info = NULL;
        }
    }

    // 赋值邻接矩阵
    for (int i = 1; i <= graph->edge_num; ++i) {
        char start_vex, end_vex;
        int row = 0, col = 0;

        printf("请输入第%d条边的两个点: ", i);
        scanf("%c %c", &start_vex, &end_vex);
        fflush(stdin);

        LocateVertex(graph, start_vex, &row);
        LocateVertex(graph, end_vex, &col);

        while (row == 0) {
            printf("第一个点不存在!\n");
            printf("请重新输入第%d条边的第一个点: ", i);
            scanf("%c", &start_vex);
            fflush(stdin);
            LocateVertex(graph, start_vex, &row);
        }
        while (col == 0) {
            printf("第二个点不存在!\n");
            printf("请重新输入第%d条边的第二个点: ", i);
            scanf("%c", &end_vex);
            fflush(stdin);
            LocateVertex(graph, end_vex, &col);
        }

        printf("请输入第%d条边的权值: ", i);
        int weight = 0;
        scanf("%d", &weight);
        fflush(stdin);

        graph->arcs[row][col].adj = weight;
        graph->arcs[col][row].adj = weight;
    }

    return SUCCESS;
}
//
// Created by kidyme on 2020/12/2.
//
// 邻接矩阵表示法
// AdjacencyMatrix
// 带权图的权值类型为int
// 将弧也称作边
//

#ifndef PRAC_C_GRAPH_H
#define PRAC_C_GRAPH_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//#define INFINITY INT_MAX // 定义+∞
#define MAX_VERTEX_NUM 21// 最多20个顶点
#define SUCCESS 1
#define ERROR 0

typedef enum {
    DG = 1,// 有向图
    DN,    // 有向网(有向权图)
    UDG,   // 无向图
    UDN    // 无向网(无向权图)
} GraphKind;

typedef struct {
    int adj;   // 若为图，则adj取值0或1表示是否邻接；若为网则表示权值大小，非邻接取值0
    char *info;// 指向该边相关信息的指针
} ArcCell, AdjacencyMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    GraphKind kind;               // 图的类型
    int vertex_num;               // 当前图的顶点数
    int edge_num;                 // 当前图的边数
    char vertexes[MAX_VERTEX_NUM];// 顶点集合(顶点向量)
    AdjacencyMatrix arcs;         // 邻接矩阵
} Graph, *GraphPtr;

void LocateVertex(GraphPtr graph, char vertex, int *index);
// 取得顶点在顶点集合中的位置

int CreateGraph(GraphPtr graph, GraphKind kind);
// 图构造

int CreateDGGraph(GraphPtr graph);
// 有向图构造

int CreateDNGraph(GraphPtr graph);
// 有向网构造

int CreateUDGGraph(GraphPtr graph);
// 无向图构造

int CreateUDNGraph(GraphPtr graph);
// 无向网构造

void PrintAdjacencyMatrix(GraphPtr graph);

//----------深度优先搜索----------------------------------------------

void DepthFirstSearch(GraphPtr graph);
// 深度优先搜索

void DFS(GraphPtr graph, int move_vertex, int assist_array[]);
// 深度优先搜索的递归函数

int GetNextVertex(GraphPtr graph, int vertex, int assist_array[]);
// 返回图中某一顶点的下一个顶点在顶点集合中的下标，需保证下一个顶点未被访问过，若已无顶点则返回0


//----------广度优先搜索----------------------------------------------

void BreadthFirstSearch(GraphPtr graph);
// 广度优先搜索


typedef struct queue {
    int front;
    int rear;
    int max_length;
    int length;
    char data[MAX_VERTEX_NUM + 1];
    int flag;// 上次出队前，是否有过空队入队
} Queue, *QueuePtr;
// 辅助队列
// 队首下标指向队首元素的上一位
QueuePtr InitQueue(int length);
// 初始化队列
int IsEmpty(QueuePtr queue);
// 判断队是否为空
int IsFull(QueuePtr queue);
// 判断队是否已满
void EnQueue(QueuePtr queue, char value);
// 入队
void DeQueue(QueuePtr queue, char *value);
// 出队
void PrintQueue(QueuePtr queue);
// 打印队列


#endif//PRAC_C_GRAPH_H

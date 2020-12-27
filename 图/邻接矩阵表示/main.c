#include "Graph.h"


int main() {
    printf("Start\n");

    GraphPtr graph = (GraphPtr) malloc(sizeof(Graph));
    CreateGraph(graph, DG);

    //------------------------打印邻接矩阵------------------------
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j) {
            printf("%d ", graph->arcs[i][j].adj);
        }
        printf("\n");
    }

    // ------------------------深度优先搜索------------------------
    DepthFirstSearch(graph);

    // ------------------------广度优先搜索------------------------
    BreadthFirstSearch(graph);


    return 0;
}

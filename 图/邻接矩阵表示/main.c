#include "Graph.h"

int main() {
    printf("Start\n");

    GraphPtr graph = (GraphPtr) malloc(sizeof(Graph));

    CreateGraph(graph, DG);

    PrintAdjacencyMatrix(graph);

    DepthFirstSearch(graph);

    BreadthFirstSearch(graph);

    return 0;
}

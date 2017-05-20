#include <stdio.h>
#include <limits.h>

#include "lib/threadville_graph.h"

int main() {

    int paths[V];

    dijkstra(graph, 1, paths);

    printf("\n\n-- \n");
    int p1[V];
    initResultArray(p1);
    thePath(1, 0, paths, p1);

    printf("\n");
    int p2[V];
    initResultArray(p2);
    thePath(1, 4, paths, p2);

    printf("\n");
    int p3[V];
    initResultArray(p3);
    thePath(1, 5, paths, p3);

    printf("\n");
    int p4[V];
    initResultArray(p4);
    thePath(1, 6, paths, p4);

    return 0;
}

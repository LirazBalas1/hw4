#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    pnode node = NULL;
    pnode *head = &node;
    char c= 'v';
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'A'){
            build_graph_cmd(head);
        }
        else if (c == 'B'){
            insert_node_cmd(head);
        }
        else if (c == 'D'){
            delete_node_cmd(head);
        }
        else if (c == 'S'){
            int src = -1;
            int dest = -1;
            int items = scanf("%d, %d\n", &src, &dest);
            if (items != 2) {
                printf("Error: Invalid input. Please enter two integers, separated by a comma.\n");
                continue;
            }
            if (src == dest) {
                printf("Error: Source and destination nodes cannot be the same.\n");
                continue;
            }
            int shortest = shortsPath_cmd(*head,src,dest);
            if (shortest == INF) {
                printf("Error: Invalid input. The source or destination node does not exist in the graph.\n");
                continue;
            }
            printf("Dijkstra shortest path: %d \n", shortest);
        }
        else if (c == 'T'){
            int tsp = TSP_cmd(*head);
            if (tsp == INF) {
                printf("Error: Invalid input. There must be at least two nodes in the graph to calculate TSP.\n");
                continue;
            }
            printf("TSP shortest path: %d \n", tsp);
        }
        else {
            printf("Error: Invalid input. Please enter a valid command (A, B, D, S, T).\n");
        }
    }
    deleteGraph_cmd(head);
    return 0;
}

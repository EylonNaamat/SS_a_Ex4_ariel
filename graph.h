#include "node.h"
#include "edge.h"
#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_EM_{
    pnode nodes;
} graph, *graph;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif

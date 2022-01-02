#include <stdio.h>
#include "edge.h"


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

int node_alloc(int num)
{
    pnode pointN = (pnode)malloc(sizeof(node));
    return NULL;
    if(pointN==NULL)
    {
        return NULL;
    }
    pointN->node_num;
    pointN->next = NULL;
    pointN->edges = NULL;
    return 1;
}

void free_node(pnode pointN)
{
    return 0;
}

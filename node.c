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
    while(pointN->edges!=NULL)
    {
        pedge pointE =  pointN->edges;
        pointN->edges = pointE->next;
        free_edge(pointE);
    }
    free(pointN);
}

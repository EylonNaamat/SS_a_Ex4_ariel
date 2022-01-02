#include <stdio.h>
#include "node.h"
#include "edge.h"

pnode node_alloc(int num)
{
    pnode pointN = (pnode)(malloc(sizeof(node)));
    if(pointN==NULL)
    {
        return NULL;
    }
    pointN->node_num = num;
    pointN->next = NULL;
    pointN->edges = NULL;
    return pointN;
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

void remove_edge(pnode pointN, int num)
{
    pedge pointE;
    if(pointN->edges==NULL)
    {
        return;
    }
    if(pointN->edges->endpoint->node_num==num)
    {
        pointE = pointN->edges;
        pointN->edges = pointN->edges->next;
        free_edge(pointE);
        return;
    }
    pointE = pointN->edges;
    pedge temp = pointN->edges->next;
    while (temp!=NULL)
    {
        if(temp->endpoint->node_num==num)
        {
           pointE->next=temp->next; 
           free_edge(temp);
        }
        else
        {
            pointE = pointE->next;
            temp=temp->next;
        }
    }
    
    
}
void add_edge(pedge pointE, pnode pointN)
{
    pointE->next = pointN->edges;
    pointN->edges = pointE;
}
void remove_edges(pnode pointN)
{
    while(pointN->edges!=NULL)
    {
        pedge pointE =  pointN->edges;
        pointN->edges = pointE->next;
        free_edge(pointE);
    }
}

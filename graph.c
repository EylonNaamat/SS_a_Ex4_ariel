#include "node.h"
#include "edge.h"
#include "graph.h"
#include <stdio.h>


pnode find_node(pnode tempgr, int num)
{
    pnode ans = NULL;
    while(tempgr!=NULL)
    {
        if(tempgr->node_num == num)
        {
            return tempgr;
        }
        tempgr=tempgr->next;
    }
    return tempgr;
}

void insert_node_cmd(pnode *head)
{

}
void delete_node_cmd(pnode *head)
{
    
}
void printGraph_cmd(pnode head) //for self debug
{
    while(head!=NULL)
    {
        printf("%d : ", head->node_num);
        pedge pointE= head->edges;
        while(pointE!=NULL)
        {
            printf("%d - ", pointE->endpoint->node_num);
            printf("%d  ", pointE->weight);
            pointE->next;
        }
       head = head->next; 
    }
}
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
{

}
void TSP_cmd(pnode head);
{

}
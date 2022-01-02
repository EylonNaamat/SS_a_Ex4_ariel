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
void deleteGraph_cmd(pnode* head)
{
    pnode* temp;
    while((*head) != NULL)
    {
        temp = (*head)->next;
        delete_node_cmd((*head));
        *head = temp;
    }
}

void build_graph_cmd(pnode * head)
{
    if((*head) != NULL)
    {
        deleteGraph_cmd(head);
    }
    char ch;
    int size;
    int num;
    scanf("%d", &size);
    (*head)= node_alloc(--size);
    if((*head) == NULL)
    {
        return;
    }
    while(size != 0)
    {
        pnode temp = node_alloc(--size);
        temp->next = (*head);
        (*head) = temp;
    }
    while(!feof(stdin) || ch != 'B' || ch != 'D' || ch != 'S' || ch != 'T')
    {
        scanf("%c", &ch);
        if(ch == 'n')
        {
            scanf("%d", &num);
            while(scanf("%d", &num))
            {
                
            }
        }
    }

}

void shortsPath_cmd(pnode head);
{

}
void TSP_cmd(pnode head);
{

}
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
    int num;
    int dist;
    int weight;
    scanf("%d", &num);
    pnode pointN = find_node(*head, num);
    if(pointN == NULL)
    {
        pointN = node_alloc(num);
        pointN->next=(*head);
        *head = pointN;
    }
    else{
    remove_edges(pointN);
    }
    while((!feof(stdin)) && (scanf("%d" , &dist)))
    {
        scanf("%d", &weight);
        pnode tempn = find_node(*head, dist);
        add_edge(edge_alloc(weight,tempn,NULL), pointN);
    }
}
void delete_node_cmd(pnode *head)
{
    int num;
    pnode startnode;
    scanf("%d",&num);
    if((*head)==NULL)
    {
        return;
    }
    if((*head)->node_num == num)
    {
        startnode = *head;
        *head=(*head)->next;
    }
    else
    {
        startnode = *head;
        pnode temp = (*head)->next;
        while(temp!=NULL)
        {
            if(temp->node_num == num)
            {
                startnode->next=temp->next;
                break;
            }
            startnode= startnode->next;
            temp = temp->next;
        }
    }
    pnode runnodes = *head;
    while(runnodes!=NULL)
    {
        remove_edge(runnodes,num);
        runnodes=runnodes->next;
    }
    free_node(startnode);
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
        free_node((*head));
        *head = temp;
    }
}

char build_graph_cmd(pnode * head)
{
    char ch = 0;
    int size;
    int node_src;
    int weight;
    int node_dest;
    pnode src;
    pnode dest;
    pedge edge = NULL;

    if((*head) != NULL)
    {
        deleteGraph_cmd(head);
    }

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

    while((!feof(stdin)) && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'A')
    {
        scanf("%c", &ch);
        if(ch == 'n')
        {
            scanf("%d", &node_src);
            src = find_node((*head), node_src);
            while((!feof(stdin)) && scanf("%d", &node_dest))
            {
                dest = find_node((*head), node_dest);
                scanf("%d", &weight);
                edge = edge_alloc(weight, dest, edge);
                add_edge(edge, src);
            }
        }
    }
    return ch;
}

void shortsPath_cmd(pnode head);
{

}
void TSP_cmd(pnode head);
{

}
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
void set_defult_value(pnode other)
{
    while(other!=NULL)
    {  
        other->prev = NULL;
        other->info = 0;
        other-> weight = __INT_MAX__;
        other = other->next;
    }
}
pnode min_not_visited(pnode other)
{
    pnode ans = NULL;
    while(other!=NULL)
    {
        if(other->info == 0)
        {
            if(other->weight!=__INT_MAX__)
            {
                if(ans == NULL)
                {
                    ans = other;
                }
                if(other->weight<ans->weight)
                {
                    ans = other;
                }
            }
        }
        other = other->next;
    }
    return ans;
}
void dijkstra_algo(pnode other ,int num)
{
    set_defult_value(other);
    pnode runNod = find_node(other, num);
    runNod->weight = 0;
    while(runNod!=NULL)
    {
        runNod->info = 1;
        pedge nedges = runNod->edges;
        while(nedges!=NULL)
        {
            pnode destN = nedges->endpoint;
            if(destN->info==0)
            {
                if((destN->weight)>((runNod->weight)+(destN->weight)))
                {
                    destN->weight = ((runNod->weight)+(destN->weight));
                    destN->prev = runNod;
                }
            }
            nedges = nedges->next;
        }
        runNod = min_not_visited(other);

    }


}
int shortsPath_cmd(pnode head,int num1,int num2)
{
    
    dijkstra_algo(head,num1);
    pnode ans = find_node(head, num2);
    if(ans == NULL)
    {
        printf("-1");
        return __INT_MAX__;
    }
    else
    {
        if(ans->weight == __INT_MAX__)
        {
            printf("-1");
            return __INT_MAX__;
        }
        else
        {
            printf("%d", ans->weight);
            return ans->weight;
        }
    }
}
void TSP_cmd(pnode head)
{
    int num;
    scanf("%d", &num);
    int *arr = (int*)(malloc(sizeof(int)*num));
    for(int i =0 ; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int TSP_helper_cmd(pnode head, int *arr,int num)
{
    int sum =0;
    for(int i=0;i<num-1;i++)
    {
        int num = shortsPath_cmd(head , arr[i],arr[i+1]);
        if(num==-1)
        {
            return __INT_MAX__;
        }
        sum+=num;
    }
    return sum;
}

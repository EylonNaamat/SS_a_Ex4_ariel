
#include "graph.h"
#include <stdio.h>
#include "edge.h"
#include "node.h"


int main()
{
    char ch;
    int size;
    int num;
    int num2;
    pnode graph;
    pnode pn;
    pnode pn2;
    pedge pe;
    while(!feof(stdin))
    {
        scanf("%c", &ch);
        if(ch == 'A')
        {
            deleteGraph_cmd(&graph);
            build_graph_cmd(&graph);
            while(graph != NULL)
            {
                pnode p = graph;
                graph = graph ->next;
                free_node(p);
            }
            scanf("%d", &size);
            graph = node_alloc(--size);
            while(size > 0)
            {
                pnode temp = node_alloc(--size);
                temp ->next = graph;
                graph = temp;
            }
        }
        if(ch == 'n')
        {
            scanf("%d", &num);
            pn = find_node(graph, num);
            while(scanf("%d", &num))
            {
                scanf("%d", &num2);
                pn2 = find_node(graph, num);
                add_edge(edge_alloc(num2, pn2, NULL), pn);
            }
        }
        if(ch == 'B')
        {
            insert_node_cmd(&graph);
        }

        if(ch == 'D')
        {
            delete_node_cmd(&graph);
        }
        
        if(ch == 'S')
        {
            shortsPath_cmd(&graph);
        }

        if(ch == 'T')
        {
            TSP_cmd(&graph);
        }

    }
}
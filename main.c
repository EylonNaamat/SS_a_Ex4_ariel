
#include "graph.h"
#include <stdio.h>
#include "edge.h"
#include "node.h"


int main()
{
    char ch;
    pnode graph;
    while(!feof(stdin))
    {
        scanf("%c", &ch);
        while(ch == 'A')
        {
            deleteGraph_cmd(&graph);
            ch = build_graph_cmd(&graph);
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
            int num1;
            int num2;
            scanf("%d %d",&num1 , &num2);
            shortsPath_cmd(&graph,num1 , num2);
        }

        if(ch == 'T')
        {
            TSP_cmd(&graph);
        }

    }
}
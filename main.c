
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
        if(ch == 'A')
        {
            deleteGraph_cmd(&graph);
            build_graph_cmd(&graph);
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
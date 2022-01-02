#include "edge.h"
#include "node.h"
#include <stdio.h>

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

pedge edge_alloc(int weight, pnode endpiont, )
{
    pedge p = (pedge)(malloc(sizeof(edge)));
    if(p == NULL)
    {
        return NULL;
    }
    p -> weight = weight;
}
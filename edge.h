#include "node.h"

typedef struct edge_ edge, *pedge;


pedge edge_alloc(int weight, pnode endpoint, pedge next);
void free_edge(pedge edge);



#include "node.h"



pnode find_node(pnode tempgr, int num);

char build_graph_cmd(pnode * head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void set_defult_value(pnode other);
pnode min_not_visited(pnode other);
void dijkstra_algo(pnode other ,int num);
int shortsPath_cmd(pnode head, int num1 , int num2);
void TSP_cmd(pnode head);
int TSP_helper_cmd(pnode head, int *arr,int num);


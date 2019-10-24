//========================================================================
// directed-graph.h
//========================================================================
// Interface for a directed graph
// a graph is defined as G = (N, E) where N is the set of is the set of nodes
// {A, B, ... } and E is the set of edges (ordered pairs) { (A,B), (B,D), ... }

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

struct node_t;
struct edge_t;
struct graph_int_t;

typedef struct node_t {
  size_t          value;  // value of the node
  size_t          edges;  // number of edges
  char            name[255];
  struct edge_t*  e_list[];
} node_t;

typedef struct edge_t {
  size_t  cost;
  node_t* next;
} edge_t;

typedef struct graph_int_t{
  size_t  nodes_size;
  node_t* source_node;
  node_t* sink_node;
  node_t* node_list[];
} graph_int_t;

void   graph_int_construct ( graph_int_t* this );
void   graph_int_destruct  ( graph_int_t* this );
size_t graph_int_size      ( graph_int_t* this );
void   graph_int_push_back ( graph_int_t* this, size_t value );

int    graph_int_at        ( graph_int_t* this, size_t idx );
int    graph_int_find      ( graph_int_t* this, size_t value );
void   graph_int_print     ( graph_int_t* this );

#endif // DIRECTED_GRAPH_H

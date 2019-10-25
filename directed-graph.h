//========================================================================
// directed-graph.h
//========================================================================
// Interface for a directed graph
// a graph is defined as G = (N, E) where N is the set of is the set of nodes
// {A, B, ... } and E is the set of edges (ordered pairs) { (A,B), (B,D), ... }

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#define MAXNAME 255

struct node_t;
struct edge_t;
struct graph_int_t;

typedef struct node_t {
  int             value;          // value of the node
  size_t          edges;          // Number of edges
  char            name[MAXNAME];  // Name of node
  struct edge_t*  e_list[];       // List of edges
} node_t;

typedef struct edge_t {
  int     cost;   // Cost of edge
  node_t* next;   // Where edge points
} edge_t;

typedef struct graph_int_t{
  size_t  nodes_size;
  node_t* source_node;
  node_t* sink_node;
  node_t* node_list[];
} graph_int_t;

void   graph_int_construct ( graph_int_t* this );
void   graph_int_destruct  ( graph_int_t* this );

void   graph_int_push_back ( graph_int_t* this, int value, char name[] );
void   graph_int_add_edge  ( graph_int_t* this, int cost, char f_node[], char t_node[] );

int    graph_int_value_at  ( graph_int_t* this, char node[]);
size_t graph_int_size      ( graph_int_t* this );
void   graph_int_print     ( graph_int_t* this );

#endif // DIRECTED_GRAPH_H

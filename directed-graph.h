//========================================================================
// directed-graph.h
//========================================================================
// Interface for a directed graph
// a graph is defined as G = (N, E) where N is the set of is the set of nodes
// {A, B, ... } and E is the set of edges (ordered pairs) { (A,B), (B,D), ... }

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

typedef struct _node_t {
  size_t  value;  // value of the node
  size_t  edges;  // number of edges
  edge_t* e_list[];
}
node_t;

typedef struct _edge_t {
  size_t  cost;
  node_t* next;
}
edge_t;

typedef struct {
  size_t  nodes_size;
  node_t* node_list[];

  node_t* source_node;
  node_t* sink_node;
}
graph_int_t;

void   graph_int_construct ( graph_int_t* this );
void   graph_int_destruct  ( graph_int_t* this );
size_t graph_int_size      ( graph_int_t* this );
void   graph_int_push_back ( graph_int_t* this, size_t value, int cost );

int    graph_int_at        ( graph_int_t* this, size_t idx );
int    graph_int_find      ( graph_int_t* this, size_t value );
void   graph_int_print     ( graph_int_t* this );

#endif // DIRECTED_GRAPH_H

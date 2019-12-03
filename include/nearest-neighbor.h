//========================================================================
// directed-graph.h
//========================================================================
// Interface for a directed graph
// a graph is defined as G = (N, E) where N is the set of is the set of nodes
// {A, B, ... } and E is the set of edges (ordered pairs) { (A,B), (B,D), ... }

#ifndef NEAREST_NEIGHBOR_H
#define NEAREST_NEIGHBOR_H

#include "directed-graph.h"


edge_t**  sorted_nodes;         // List of ordered sorted nodes
edge_t**  sorted_edges;         // List of ordered sorted edges

void nn_shortest_path ( graph_int_t* this );

#endif // NEAREST_NEIGHBOR_H

//========================================================================
// directed-graph.h
//========================================================================
// Interface for a directed graph
// a graph is defined as G = (N, E) where N is the set of is the set of nodes
// {A, B, ... } and E is the set of edges (ordered pairs) { (A,B), (B,D), ... }

#ifndef NEAREST_NEIGHBOR_H
#define NEAREST_NEIGHBOR_H

#include "directed-graph.h"


node_t**  sorted_nodes;         // List of ordered sorted nodes
edge_t**  sorted_edges;         // List of ordered sorted edges
size_t    sorted_nodes_size;
size_t    edges_size;           // Number of edges

// Calculates sorted nodes and edges
void nn_shortest_path_fc ( graph_int_t* this );

// Prints graph
void nn_shortest_path_print( graph_int_t* this );

// Returns nodes and edges
void nn_shortest_path_nodes( node_t**  nodes );
void nn_shortest_path_edges( edge_t**  edges );

#endif // NEAREST_NEIGHBOR_H

//========================================================================
// nearest-neightbor.c
//========================================================================
// Implementation of the nearest neghbor fuctions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nearest-neighbor.h"

//------------------------------------------------------------------------
// nn_shortest_path
//------------------------------------------------------------------------
// Uses nearest neighbor heuristic to find the shortest path in the graph
// Begin with source node and chose shortest edges to get to sink node (t)

void nn_shortest_path( graph_int_t* this )
{
  // allocate memmory for the nodes and edges
  sorted_nodes = ( node_t** ) malloc ( this->nodes_size * of ( node_t* ) );
  sorted_edges = ( edge_t** ) malloc ( ( this->nodes_size - 1 ) * of ( edge_t* ) );

  for ( size_t i = 0; i < this->source_node->edges_size; i++ ) {

  }
}

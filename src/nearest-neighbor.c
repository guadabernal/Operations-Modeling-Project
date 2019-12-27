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
// ** Assuming every node has edge that will lead to sink **
// _fc = fully connected

void nn_shortest_path_fc( graph_int_t* this )
{
  // allocate memmory for the nodes and edges of max possible size
  sorted_nodes = ( node_t** ) malloc ( this->nodes_size * sizeof ( node_t* ) );
  sorted_edges = ( edge_t** ) malloc ( ( this->nodes_size - 1 ) * sizeof ( edge_t* ) );

  node_t* curr = this->source_node;
  int index = 0; // index for sorted nodes and edges

  while ( curr != this->sink_node ) {
    // i_min keeps track of edge with smallest list
    int dist = curr->edges[0]->cost;
    int i_min = 0;

    // Save lowest cost edge location
    for ( int i = 1; i < curr->edges_size; i++ ) {
      if ( curr->edges[i]->cost < dist ) {
        dist = curr->edges[i]->cost;
        i_min = i;
      }
    }

    // At the current index add the current node and edge to next spot
    sorted_nodes[index] = curr;
    sorted_edges[index] = curr->edges[i_min];

    curr = curr->edges[i_min]->next;
    index += 1;
  }

  // add sink node
  sorted_nodes[3] = this->sink_node;

  sorted_nodes_size = 4;
  edges_size = 3;
}

//------------------------------------------------------------------------
// nn_shortest_path_print
//------------------------------------------------------------------------
// Prints graph of selected nodes and edges

void nn_shortest_path_print( graph_int_t* this )
{
  // Iterrate through the nodes in list printing their value and edges
  for( size_t i = 0; i < sorted_nodes_size; i++ ){
    printf("  here i = %zu \n", i);
    if ( sorted_nodes[i] == this->source_node )
      printf( "    - SNode : %s  ", sorted_nodes[i]->name );
    else if ( sorted_nodes[i] == this->sink_node )
      printf( "    - TNode : %s  ", sorted_nodes[i]->name );
    else
      printf( "    -  Node : %s  ", sorted_nodes[i]->name );

    // Print Nodes
    printf( "         Edge from  %s  ", sorted_nodes[i]->name );
    printf( "to  %s  ", sorted_edges[i]->next->name );
    printf( "with cost of  %d \n", sorted_edges[i]->cost );
  }
}

//------------------------------------------------------------------------
// nn_shortest_path_nodes
//------------------------------------------------------------------------
// returns nodes

void nn_shortest_path_nodes( node_t**  nodes )
{
  nodes = sorted_nodes;
}

//------------------------------------------------------------------------
// nn_shortest_path_edges
//------------------------------------------------------------------------
// returns edges

void nn_shortest_path_edges( edge_t**  edges )
{
  edges = sorted_edges;
}

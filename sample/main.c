#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directed-graph.h"
#include "nearest-neighbor.h"

int main(){
  // Constructing
  printf( "\n   ----- Setting up Graph ----- \n\n" );
  graph_int_t graph1;
  graph_int_construct( &graph1 );

  // Adding nodes
  graph_int_push_back( &graph1, 7, "node A" );
  graph_int_push_back( &graph1, 3, "node B" );
  graph_int_push_back( &graph1, 8, "node C" );
  graph_int_push_back( &graph1, 3, "node D" );

  // Set Source and sink nodes
  graph_int_set_source( &graph1, "node A" );
  graph_int_set_sink( &graph1, "node D" );

  // Adding Edge
  graph_int_add_edge( &graph1, 15, "node A", "node B" );
  graph_int_add_edge( &graph1, 7, "node D", "node B" );
  graph_int_add_edge( &graph1, 133, "node B", "node C" );
  graph_int_add_edge( &graph1, 2, "node D", "node C" );

  // Print Value at Nodes
  printf( "     value at node A = %d\n", graph_int_value_at( &graph1, "node A" ) );
  printf( "     value at node C = %d\n", graph_int_value_at( &graph1, "node C" ) );

  // Printing Graph
  printf( "\n   ----- Completed Graph Setup ----- \n\n" );
  graph_int_print( &graph1 );

  // Calcluate the minimum tree from source to sink
  printf( "\n   ----- Implementing Nearest Neighbor Heuristic ----- \n\n" );



  printf( "   Destructing Graph\n" );
  graph_int_destruct( &graph1 );

}

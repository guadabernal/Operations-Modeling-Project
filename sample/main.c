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
  graph_int_push_back( &graph1, 8, "node E" );
  graph_int_push_back( &graph1, 3, "node F" );

  // Set Source and sink nodes
  graph_int_set_source( &graph1, "node A" );
  graph_int_set_sink( &graph1, "node F" );

  //      B  ->  D
  //  A                 F
  //      C  ->  E

  // Adding Edge
  graph_int_add_edge( &graph1, 15, "node A", "node B" );
  graph_int_add_edge( &graph1, 7, "node A", "node C" );
  graph_int_add_edge( &graph1, 3, "node B", "node D" );
  graph_int_add_edge( &graph1, 12, "node B", "node E" );
  graph_int_add_edge( &graph1, 5, "node C", "node D" );
  graph_int_add_edge( &graph1, 9, "node C", "node E" );
  graph_int_add_edge( &graph1, 1, "node D", "node F" );
  graph_int_add_edge( &graph1, 2, "node E", "node F" );


  // Print Value at Nodes
  printf( "     value at node A = %d\n", graph_int_value_at( &graph1, "node A" ) );
  printf( "     value at node C = %d\n", graph_int_value_at( &graph1, "node C" ) );

  // Printing Graph
  printf( "\n   ----- Completed Graph Setup ----- \n\n" );
  graph_int_print( &graph1 );

  // Calcluate the minimum tree from source to sink
  printf( "\n   ----- Implementing Nearest Neighbor Heuristic ----- \n\n" );
  nn_shortest_path_fc( &graph1 );
  nn_shortest_path_print( &graph1 );

  printf( "   Destructing Graph\n" );
  graph_int_destruct( &graph1 );

}

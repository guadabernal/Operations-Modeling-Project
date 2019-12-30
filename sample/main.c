#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directed-graph.h"
#include "nearest-neighbor.h"

int main(){
  // Constructing
  printf( "\n   ----- Setting up Graphs ----- \n\n" );
  graph_int_t graph1;
  graph_int_t graph2;
  graph_int_construct( &graph1 );
  graph_int_construct( &graph2 );

  // Adding nodes GRAPH 1 ------------------
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

  // Adding Edges
  graph_int_add_edge( &graph1, 15, "node A", "node B" );
  graph_int_add_edge( &graph1, 7, "node A", "node C" );
  graph_int_add_edge( &graph1, 3, "node B", "node D" );
  graph_int_add_edge( &graph1, 12, "node B", "node E" );
  graph_int_add_edge( &graph1, 5, "node C", "node D" );
  graph_int_add_edge( &graph1, 9, "node C", "node E" );
  graph_int_add_edge( &graph1, 1, "node D", "node F" );
  graph_int_add_edge( &graph1, 2, "node E", "node F" );

  // Adding nodes  GRAPH 2 ------------------
  graph_int_push_back( &graph2, 7, "node A" );
  graph_int_push_back( &graph2, 3, "node B" );
  graph_int_push_back( &graph2, 8, "node C" );
  graph_int_push_back( &graph2, 8, "node E" );
  graph_int_push_back( &graph2, 3, "node F" );

  // Set Source and sink nodes
  graph_int_set_source( &graph2, "node A" );
  graph_int_set_sink( &graph2, "node F" );

  //      B
  //  A                 F
  //      C  ->  E

  // Adding Edge
  graph_int_add_edge( &graph2, 15, "node A", "node B" );
  graph_int_add_edge( &graph2, 33, "node A", "node C" );
  graph_int_add_edge( &graph2, 9, "node C", "node E" );
  graph_int_add_edge( &graph2, 2, "node E", "node F" );

  // Print Value at Nodes
  printf( "     value at node A = %d\n", graph_int_value_at( &graph1, "node A" ) );
  printf( "     value at node C = %d\n", graph_int_value_at( &graph1, "node C" ) );

  // Printing Graph
  printf( "\n   ----- Completed Graph Setup ----- \n\n" );
  printf( "\n   Graph 1 ----- \n\n" );
  graph_int_print( &graph1 );
  printf( "\n   Graph 2 ----- \n\n" );
  graph_int_print( &graph2 );

  // Calcluate the minimum tree from source to sink
  printf( "\n   ----- Implementing Nearest Neighbor Heuristic ----- \n\n" );
  printf( "\n    Fully Connected ----- \n\n" );
  nn_shortest_path_fc( &graph1 );
  nn_shortest_path_print( &graph1 );

  printf( "\n    Connected ----- \n\n" );
  nn_shortest_path_c( &graph2 );
  nn_shortest_path_print( &graph2 );

  printf( "\n   ----- Destructing Graphs ----- \n\n" );
  graph_int_destruct( &graph1 );
  graph_int_destruct( &graph2 );

}

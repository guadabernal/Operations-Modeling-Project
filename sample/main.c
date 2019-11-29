#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directed-graph.h"

int main(){
  printf("  1. Constructing\n");
  graph_int_t graph1;
  graph_int_construct( &graph1 );

  printf("  2. Adding a node\n");
  graph_int_push_back( &graph1, 7, "node A");
  graph_int_push_back( &graph1, 3, "node B");
  graph_int_push_back( &graph1, 8, "node C");
  graph_int_push_back( &graph1, 3, "node D");

  printf("  3. Printing Graph\n");
  graph_int_print( &graph1 );

  printf("  4. Adding Edge\n");
  graph_int_add_edge( &graph1, 15, "node A", "node B");
  graph_int_add_edge( &graph1, 7, "node D", "node B");
  graph_int_add_edge( &graph1, 133, "node B", "node C");
  graph_int_add_edge( &graph1, 2, "node D", "node C");

  printf("  5. Printing Graph\n");
  graph_int_print( &graph1 );

  printf("  6. Destructing\n");
  graph_int_destruct( &graph1 );

  printf("\nhey you made it!!\n");
}

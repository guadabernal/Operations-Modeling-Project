//========================================================================
// directed-graph.c
//========================================================================
// Implementation of the directed graph creation functions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directed-graph.h"

//------------------------------------------------------------------------
// graph_int_construct
//------------------------------------------------------------------------
// Construct the graph_int_t and initialize the fields inside.

void graph_int_construct( graph_int_t* this )
{
  this->nodes_size = 0;
  this->source_node = NULL;
  this->sink_node = NULL;
}

//------------------------------------------------------------------------
// graph_int_destruct
//------------------------------------------------------------------------
// Destruct the graph_int_destruct, freeing any dynamically allocated memory

void graph_int_destruct( graph_int_t* this )
{
  // free the edges inside of each node
  for( size_t i = 0; i < this->nodes_size; i++) {
    for( size_t j = 0; j < this->node_list[i]->edges; j++) {
      edge_t* temp = this->node_list[i]->e_list[j];
      free( temp );
    }
  }

  // Reset values in this
  this->nodes_size = 0;
  this->source_node = NULL;
  this->sink_node = NULL;
}

//------------------------------------------------------------------------
// graph_int_push_back
//------------------------------------------------------------------------
// Push a new node into the graph

void graph_int_push_back( graph_int_t* this, size_t value, char name[] )
{
  // Creates a new node and assigns its 'value' field value
  node_t* new_node = ( node_t* ) malloc ( sizeof ( node_t ) );
  new_node->value = value;
  new_node->edges = 0;
  memcpy(new_node->name, name, 6);
  printf( "     created new node  %s  ", new_node->name);
  printf( "     with value %zu\n", new_node->value);

  // Update graph values
  this->sink_node = new_node;
  this->node_list[this->nodes_size] = new_node;
  this->nodes_size++;
  if( this->nodes_size == 2 ){
    printf( "  **  - Value: %zu \n", this->node_list[0]->value );
    printf( "  **  - Value: %zu \n", this->node_list[1]->value );
  }

  printf( "     size of graph = %zu  \n", this->nodes_size);
  printf( "     list -> new node  %s  ", this->node_list[this->nodes_size - 1]->name);
  printf( "     with value = %zu\n\n\n", this->node_list[this->nodes_size - 1]->value);
}

//------------------------------------------------------------------------
// graph_int_add_edge
//------------------------------------------------------------------------
// Adds a new edge into the graph

void graph_int_add_edge( graph_int_t* this, size_t cost, char f_node[], char t_node[] )
{
  if( f_node == t_node ) printf("ERROR: Invalid Edge \n");

  // Creates a new edge and assigns its 'cost' field value
  edge_t* edge = ( edge_t* ) malloc ( sizeof ( edge_t ) );
  edge->cost = cost;

  // Add new edge pointers
  for( size_t i = 0; i < this->nodes_size; i++ ){
    if( strcmp( f_node, this->node_list[i]->name ) == 0 ) {
      this->node_list[i]->e_list[this->node_list[i]->edges] = edge;
      this->node_list[i]->edges++;
    }
    if( strcmp( t_node, this->node_list[i]->name ) == 0 ) {
      edge->next = this->node_list[i];
    }
  }
}

//------------------------------------------------------------------------
// list_int_at
//------------------------------------------------------------------------
// Pointer chase and return the value at the given index
// If the index is out of bound, then return 0.

int graph_int_value_at( graph_int_t* this, char node[] )
{
  return 0;
}

//------------------------------------------------------------------------
// graph_int_size
//------------------------------------------------------------------------
// Get the number of nodes in the graph.

size_t graph_int_size( graph_int_t* this )
{
  return this->nodes_size;
}

//------------------------------------------------------------------------
// graph_int_print
//------------------------------------------------------------------------
// Print out the content of graph_int_t.

void graph_int_print( graph_int_t* this )
{

  printf( "  **  - Value: %zu \n", this->node_list[0]->value );
  printf( "  **  - Value: %zu \n", this->node_list[1]->value );

  // Iterrate through the nodes in list printing their value and  edges
  for( size_t i = 0; i < this->nodes_size; i++ ){
    printf( "    - Node : %s  ", this->node_list[i]->name );
    printf( "    - i : %zu  ", i );
    printf( "    - Value: %zu \n", this->node_list[i]->value );

    // Iterrate through edges in current node
    for( size_t j = 0; j < this->node_list[i]->edges; j++ ){
      printf( "        Edge from  %s  ", this->node_list[i]->name );
      printf( "to  %s  ", this->node_list[i]->e_list[j]->next->name );
      printf( "with cost of  %zu \n", this->node_list[i]->e_list[j]->cost );
    }
  }
  printf("\n");
}

int main(){
  printf("  1. Constructing\n");
  graph_int_t graph1;
  graph_int_construct( &graph1 );

  printf("  2. Adding a node\n");
  graph_int_push_back( &graph1, 7, "node A");
  graph_int_push_back( &graph1, 3, "node B");

  printf("  3. Printing Graph\n");
  graph_int_print( &graph1 );

  printf("  4. Adding Edge\n");
  graph_int_add_edge( &graph1, 15, "node A", "node B");

  printf("  5. Printing Graph\n");
  graph_int_print( &graph1 );

  printf("  6. Destructing\n");
  graph_int_destruct( &graph1 );

  printf("\nhey you made it!!\n");
}

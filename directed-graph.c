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
  this->nodes  = ( node_t** ) malloc ( sizeof ( node_t* ) );
  this->nodes_size = 0;
  this->nodes_cap = 1;

  this->source_node = NULL;
  this->sink_node = NULL;
}

//------------------------------------------------------------------------
// graph_int_destruct
//------------------------------------------------------------------------
// Destruct the graph_int_destruct, freeing any dynamically allocated memory

void graph_int_destruct( graph_int_t* this )
{
  // free the edges and the list of edges inside of each node
  for( size_t i = 0; i < this->nodes_size; i++) {
    for( size_t j = 0; j < this->nodes[i]->edges_size; j++) {
      edge_t* temp = this->nodes[i]->edges[j];
      free( temp );
    }
    free( this->nodes[i]->edges );
  }

  // free the list of nodes
  free( *this->nodes );

  // Reset values in this
  this->nodes_size = 0;
  this->source_node = NULL;
  this->sink_node = NULL;
}

//------------------------------------------------------------------------
// graph_int_push_back
//------------------------------------------------------------------------
// Push a new node into the graph

void graph_int_push_back( graph_int_t* this, int value, char name[] )
{
  // Creates a new node and assigns its 'value' field value
  node_t* new_node = ( node_t* ) malloc ( sizeof ( node_t ) );
  new_node->edges  = ( edge_t** ) malloc ( sizeof ( edge_t* ) );
  new_node->value = value;
  new_node->edges_size = 0;
  new_node->edges_cap = 1;

  memcpy(new_node->name, name, 255);

  // Update graph values
  this->sink_node = new_node;

  if( this->nodes_size == this->nodes_cap ){
    this->nodes_cap *= 2;
    this->nodes = ( node_t** ) realloc ( this->nodes, this->nodes_cap * sizeof ( node_t* ) );
  }

  this->nodes[this->nodes_size] = new_node;
  this->nodes_size++;
}

//------------------------------------------------------------------------
// graph_int_add_edge
//------------------------------------------------------------------------
// Adds a new edge into the graph

void graph_int_add_edge( graph_int_t* this, int cost, char f_node[], char t_node[] )
{
  if( f_node == t_node ) printf("ERROR: Invalid Edge \n");

  // Creates a new edge and assigns its 'cost' field value
  edge_t* edge = ( edge_t* ) malloc ( sizeof ( edge_t ) );
  edge->cost = cost;

  // Add new edge pointers
  for( size_t i = 0; i < this->nodes_size; i++ ){
    // Assign the pointer in the node edgeList to the new edge
    if( strcmp( f_node, this->nodes[i]->name ) == 0 ) {
      this->nodes[i]->edges[this->nodes[i]->edges_size] = edge;
      this->nodes[i]->edges_size++;
    }

    // Assign the pointer next in the edge struct to the tail node
    if( strcmp( t_node, this->nodes[i]->name ) == 0 ) {
      edge->next = this->nodes[i];
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
  // Iterrate through the nodes in list printing their value and  edges
  for( size_t i = 0; i < this->nodes_size; i++ ){
    printf( "    - Node : %s  ", this->nodes[i]->name );
    printf( "    - Value: %d \n", this->nodes[i]->value );

    // Iterrate through edges in current node
    for( size_t j = 0; j < this->nodes[i]->edges_size; j++ ){
      printf( "        Edge from  %s  ", this->nodes[i]->name );
      printf( "to  %s  ", this->nodes[i]->edges[j]->next->name );
      printf( "with cost of  %d \n", this->nodes[i]->edges[j]->cost );
    }
  }
  printf("\n");
}

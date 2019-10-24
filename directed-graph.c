//========================================================================
// directed-graph.c
//========================================================================
// Implementation of the directed graph creation functions.

#include <stdio.h>
#include <stdlib.h>
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
  for( int i = 0; i < this->nodes_size; i++) {
    free(this->node_list[i]->e_list);
  }

  // free the list of nodes
  free ( this->node_list );

  // Reset values in this
  this->nodes_size = 0;
  this->source_node = NULL;
  this->sink_node = NULL;
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
// graph_int_push_back
//------------------------------------------------------------------------
// Push a new node into the graph

void graph_int_push_back( graph_int_t* this, int value )
{
  // Creates a new node and assigns its 'value' field value
  node_t* new_node = ( node_t* ) ece2400_malloc ( sizeof ( node_t ) );
  new_node->value = value;

  // Assign values to the new node's pointer variables. If the tail_ptr is not null
  // then tail_ptr->next_ptr must be re-assigned before the tail_ptr is moved to the new_node
  if ( this->tail_ptr != NULL ) {
    this->tail_ptr->next_ptr  = new_node;
    new_node->prev_ptr        = this->tail_ptr;
  }
  else {
    new_node->prev_ptr = NULL;
  }
  new_node->next_ptr = NULL;

  // Modifies the 'this' tail pointer and if necessary, (in the case that this is
  // the first node) the head_ptr, to point at the new node as well
  this->tail_ptr = new_node;
  if ( this->head_ptr == NULL ) this->head_ptr = new_node;

  // Increment the size of the list
  this->size++;
}

//------------------------------------------------------------------------
// list_int_at
//------------------------------------------------------------------------
// Pointer chase and return the value at the given index
// If the index is out of bound, then return 0.

// int list_int_at( list_int_t* this, size_t idx )
// {
//   // Checks if the index is larger than the size and returns 0
//   if( idx >= this->size ) {
//     return 0;
//   }
//
//   // Iterates through idx nodes with the temp variable and returns
//   // the value at the idx index
//   node_t* temp;
//
//   temp = this->head_ptr;
//   for( size_t i = 0; i < idx; i++ ){
//     temp = temp->next_ptr;
//   }
//
//   return (int)temp->value;
// }

//------------------------------------------------------------------------
// graph_int_print
//------------------------------------------------------------------------
// Print out the content of graph_int_t.

void graph_int_print( graph_int_t* this )
{
  // Iterrate through the nodes in list printing their value and  edges
  for( size_t i = 0; i < this->nodes_size; i++ ){
    printf ( "    Node : %s  Value: %zu \n", this->node_list[i]->name,
        this->node_list[i]->value );
    for( size_t j = 0; j < this->node_list[i]->edges; j++ ){
      printf ( "        Edge from: %s  To: %s Cost: %zu \n",
          this->node_list[i]->name,
          this->node_list[i]->e_list[j]->next->name,
          this->node_list[i]->e_list[j]->cost );
    }
  }
  printf("\n");
}



int main(){
  printf("\n\nhey you made it!!\n ");

}

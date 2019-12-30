//========================================================================
// nearest-neightbor.c
//========================================================================
// Implementation of the nearest neghbor fuctions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nearest-neighbor.h"

//------------------------------------------------------------------------
// nn_shortest_path_fc
//------------------------------------------------------------------------
// Uses nearest neighbor heuristic to find the shortest path in the graph
// Begin with source node and chose shortest edges to get to sink node (t)
// ** Assuming every node has edge that will lead to sink **

void nn_shortest_path_fc( graph_int_t* this )
{
  // allocate memmory for the nodes and edges of max possible size
  sorted_nodes = ( node_t** ) malloc ( this->nodes_size * sizeof ( node_t* ) );
  sorted_edges = ( edge_t** ) malloc ( ( this->nodes_size - 1 ) * sizeof ( edge_t* ) );
  sorted_nodes_size = 0;
  edges_size = 0;

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
    sorted_nodes_size++;
    edges_size++;

    curr = curr->edges[i_min]->next;
    index += 1;
  }

  // add sink node
  sorted_nodes[index] = this->sink_node;
  sorted_nodes_size++;
}

//------------------------------------------------------------------------
// nn_shortest_path_c
//------------------------------------------------------------------------
// Uses nearest neighbor heuristic to find the shortest path in the graph
// Begin with source node and chose shortest edges to get to sink node (t)
// ** Assuming there is an edge that will lead to sink **

int nn_recur_help( graph_int_t* this, node_t* curr, int index)
{
  int edges_s  = curr->edges_size;

  if ( curr  == this->sink_node ) {
    //sorted_nodes[index] = curr;
    //sorted_edges[index] = curr->edges[i_min];
    sorted_nodes_size++;
    edges_size++;
    return 1;
  }

  else if ( edges_s == 0 )
    return 0;

  // fill an unsorted array with the edges
  edge_t* sort_arr[edges_s];
  for ( int i = 0; i < edges_s; i++ )
    sort_arr[i] = curr->edges[i];

  // sort the edges
  for ( int i = 0; i < edges_s; i++ ) {
    for ( int j = i + 1; j < edges_s; j++ ) {
      if ( sort_arr[i]->cost > sort_arr[j]->cost ) {
        edge_t* a =  sort_arr[i];
        sort_arr[i] = sort_arr[j];
        sort_arr[j] = a;
      }
    }
  }

  // go through edges until sink is found
  for(int i = 0; i < edges_s; i++ ) {
    if( nn_recur_help( this, curr->edges[i]->next, index++ ) == 1 )
      return 1;
    index = index - 1;
  }

  return 0;
}

void nn_shortest_path_c( graph_int_t* this )
{
  printf("\n\n began \n\n");
  node_t* curr = this->source_node;
  nn_recur_help( this, curr, 0 );
  printf("\n\n got out \n\n");
  printf("\n\n sorted_nodes_size %zu \n\n", sorted_nodes_size);
  printf("\n\n edges_size %zu \n\n", edges_size);
}

//------------------------------------------------------------------------
// nn_shortest_path_print
//------------------------------------------------------------------------
// Prints graph of selected nodes and edges

void nn_shortest_path_print( graph_int_t* this )
{
  int cost = 0;

  // Iterrate through the nodes in list printing their value and edges
  for ( size_t i = 0; i < sorted_nodes_size; i++ ) {
    // Print edges
    if ( sorted_nodes[i] == this->source_node )
      printf( "    - SNode : %s  \n", sorted_nodes[i]->name );
    else if ( sorted_nodes[i] == this->sink_node )
      printf( "    - TNode : %s  \n", sorted_nodes[i]->name );
    else
      printf( "    - Node : %s  \n", sorted_nodes[i]->name );

    // Print edges
    if( i < edges_size ) {
      printf( "         Edge from  %s  ", sorted_nodes[i]->name );
      printf( "to  %s  ", sorted_edges[i]->next->name );
      printf( "with cost of  %d \n", sorted_edges[i]->cost );
      cost += sorted_edges[i]->cost;
    }
  }

  printf( "         Total Cost = %d  \n", cost );
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

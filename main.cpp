//
//	Homework 2 - Implement Dijkstra's Algorithm and compute shortest paths between vertices in a graph
//

#include <assert.h>
#include <iostream>
#include "Graph.hpp"
#include "MinimumSpanningTree.hpp"


/** Main entry for program
  *
  */
int main()
{
	Graph graph("input.txt");

	//
	// Print graph and MST
	//

	std::cout << "Graph:" << std::endl << std::endl;

	std::cout << graph << std::endl;

	MinimumSpanningTree::PrintMinimumSpanningTree(graph);

	return 0;
} // main

//
// MinimumSpanningTree.hpp - Contains class used to compute the MST
//

#pragma once

#include "Graph.hpp"

//
// MinimumSpanningTree - Implements Janik-Prim's algorith to find the MST
//
class MinimumSpanningTree
{
public:

	//
	// Description:
	//
	//		Prints the MST cost of a graph and the path associated with the MST
	//
	// Parameters:
	//
	//		Graph& graph -graph
	//
	//		int sourceVertex - source vertex
	//
	//
	static void PrintMinimumSpanningTree(
		const Graph& graph,
		int sourceVertex = 0);
};


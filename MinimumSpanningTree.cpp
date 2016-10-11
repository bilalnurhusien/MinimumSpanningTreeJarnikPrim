//
// MinimumSpanningTree.cpp - Contains class used to compute the MST
//

#include <functional>
#include <algorithm>

#include "MinimumSpanningTree.hpp"


//
// Vertex struct used to contain the edge cost of a vertex
//
struct Vertex
{
	int vertex;
	int edge;

	bool operator<(const Vertex& val) const
	{
		return vertex < val.vertex;
	}
};

//
// GreaterDistComp contains a comparator used in creating a min heap
//
struct GreaterDistComp
{
	bool operator()(const Vertex& lhs,const Vertex& rhs) const
	{
		return lhs.edge > rhs.edge;
	}
};

void MinimumSpanningTree::PrintMinimumSpanningTree(
	const Graph& graph,
	int sourceVertex)
{
	//
	// Closed set contains all explored vertices
	// Open set contains all unexplored vertics
	//
	std::vector<Vertex> closedSet;
	std::vector<Vertex> openSet;

	//
	// Start at source vertex with edge cost zero
	//
	Vertex source = {sourceVertex, 0};

	openSet.push_back(source);

	//
	// Set all other vertex edge cost to infinity
	//
	for (int i = 0; i < graph.GetNumberOfVertices(); ++i)
	{
		if (i != sourceVertex)
		{
			openSet.push_back({i, INFINITY_INT});
		}
	}

	std::vector<int> neighbours;

	//
	// Use std::make_heap to create a min heap
	//
	std::make_heap(openSet.begin(), openSet.end(), GreaterDistComp());

	//
	// Use the following variables to keep track of the MST cost and path
	//
	uint32_t mstCost = 0;

	std::string mstPath;

	while (false == openSet.empty())
	{
		//
		// Pop min value from min heap
		//
		std::pop_heap(openSet.begin(), openSet.end(), GreaterDistComp());

		Vertex minPath = openSet.back();

		openSet.pop_back();

		closedSet.push_back(minPath);

		mstCost += minPath.edge;

		if (openSet.empty())
		{
			mstPath = "|" + mstPath + std::to_string(minPath.vertex) + "|";
		}
		else
		{
			mstPath = "|" +  mstPath + std::to_string(minPath.vertex) + "|" + " -> ";
		}

		graph.GetNeighbours(minPath.vertex, neighbours);

		bool updateHeap = false;

		//
		// Iterate through neighbours and update the edge costs in the open set
		//
		for (int i = 0; i < neighbours.size(); ++i)
		{
			Vertex neighbour =
			{
				neighbours[i],
				graph.GetEdgeValue(minPath.vertex, neighbours[i]),
			};

			for (auto& it : openSet)
			{
				if (neighbour.vertex == it.vertex &&
					neighbour.edge < it.edge)
				{
					it.edge = neighbour.edge;

					updateHeap = true;
				}
			}
		}

		if (updateHeap)
		{
			//
			// Update min heap since we modified the values
			//
			std::make_heap(openSet.begin(), openSet.end(), GreaterDistComp());
		}
	}

	std::cout << "MST cost is: " << mstCost << std::endl;

	std::cout << "MST path is: " << mstPath << std::endl;

}

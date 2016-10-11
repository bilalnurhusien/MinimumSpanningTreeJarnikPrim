Date: October 9, 2016

Brief:

	This program was created for the C++ for C programmers Part 1 course on coursera.
	It uses Jarnik-Prim's algorithm to find the minimum spanning tree cost of a graph.
	To compile the code, run make. To run the program, enter ./main

Description:

	There are two main classes in this project:

	1. The Graph class is used to create and store a 2 dimensional graph using an
	adjacency matrix. The Graph class has three constructors. One constructor can be
	used to generate an undirectional graph using a density and size parameter.
	Another Graph constructor is used to initialize the graph directly using a 2
	dimensional vector. The final constructor can be used to read in a file containing
	an adjacency list. It uses this list to construct a graph.

	2. The MinimumSpanningTree class uses Jarnik-Prim's algorithm to determine the MST of a graph.
	It also prints out an MST path from the source.

	Finally, main.cpp contains the entry point of the program. The main program outputs 
	the graph contents and the MST cost and path from the source vertex.

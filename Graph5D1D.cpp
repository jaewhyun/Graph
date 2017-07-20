// Author: John Maslanka  Program: Graph5D1D.cpp
// Date: 27-Dec-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
// Elementary Illustration of a Directed Graph adapted from 
// Figures 15.2 and 15.3 in Main and Savitch, but terminal 
// input is available. The program asks the user how many
// vertices to enter. (MAX is 100.) If the user enters 100, 
// the vertex numbers are from 0 to 99. The user then enters the
// edges by giving the start vertex followed by the end vertex
// up to the product of the number of vertices times the 
// number of vertices less 1, or you can terminate edge input  
// with control-z. 
// 5-Dec-2016 -- Note: The numeric value of the start vertex 
// of an edge must be less than that of the end vertex.

#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

class Graph {
private:
	bool    edge [MAX][MAX];
	int     count_of_vertices;
	int		vflag [MAX];
public:
	Graph () { count_of_vertices = 0; }
	int size () const {return count_of_vertices; }

	void add_vertexes (const int);
	void add_edge (int source, int target);
	bool get_edge (int a, int b) { return edge [a][b]; }
	bool is_edge (int source, int target) const;
	void tree_level (int, int);
	void clear_vflags(int);
	void clear_vflag(int);
	void set_vflag(int);
	int  test_vflag(int);
	void displayAdjacencyMatrix(int);
};

void Graph::add_vertexes (const int nr)
{ int x, y;
  count_of_vertices = nr;
  for (x = 0; x < nr; ++x)
	 for (y = 0; y < nr; ++y)
	    edge[x][y] = false; }
void Graph::add_edge(int source, int target)
{
	edge[source][target] = true;
}
bool Graph::is_edge(int source, int target) const
{
	return edge[source][target];
}
void Graph::tree_level (int x, int level)
{ int j, i;
  ++level;
  for (j = 0; j < size(); ++j)
	 { if (is_edge (x, j))
		{ for (i = 1; i < level ; cout << "   ", ++i);
		  cout << "  (" << x << ", " << j << ")" << endl;
		  if ( x != j )
			  tree_level (j, level);
	    }
	 }
}

void Graph::displayAdjacencyMatrix(int nr) {
	char dispEdge[MAX];
	for (int x = 0; x < nr; x++) {
		cout << x;
		for (int y = 0; y < nr; y++)
			dispEdge[y] = ' ';
		for (int y = 0; y < nr; y++)
			if (edge[x][y])
				dispEdge[y] = 'e';
		for (int y = 0; y < nr; y++)
			cout << "  " << dispEdge[y];
		cout << endl;
	}
	cout << endl;
}

int main () {
    Graph G;
	int i, j, nr, x;
	cout << "Enter number of vertices (1 < nr <= 100) ";
	cin >> nr;
	if (!cin.eof() && cin.good() && nr >= 2 && nr <= MAX)
	{
	G.add_vertexes(nr);
	cout << "Number of vertices is " << G.size() << endl << endl;
	cout << " Numbers of Beginning and Terminating vertexes must be between 0 and "
		<< (nr - 1) << " inclusive" << endl;
	cout << "Number of Beginning vertex must be less than that of Terminating vertex."
			<< endl;
	cout << "Enter EOF at keyboard to view displays." << endl;
	for (x = 0; x < nr*(nr-1) && !cin.eof();)
	{
		cout << "Enter the two bounding vertexes of an edge " << endl;
		cin >> i >> j;
		if (!cin.eof() && cin.good() && i < nr && j < nr && i < j)
		{
			G.add_edge(i, j);
			++x;
		}
		else
			if (!cin.eof() && cin.good()) {
				if (i >= j)
					cout << "Input values out of order.";
				else
					cout << "One or more input values out of range.";
				cout << "Please re-enter." << endl;
			}
			else
			// This option needs some proper recovery code.
				if (!cin.eof()) {
					cout << "Invalid input. Program exiting." << endl;
					exit(1);
					}
				else
				cout << "Your current input gives." << endl;
				}
		}
		cout << endl << "Adjacency Matrix" 
			<< " -- e signifies an Edge in your Graph" << endl;
		cout << "   0  1  2  3  4  5  6  7  8  9 10" << endl;
		G.displayAdjacencyMatrix (nr);
		cout << "Directed List of Neighbor Vertexes for each Vertex"
			<< endl;
		for (i = 0; i < G.size(); ++i)
		{
			cout << "For Vertex " << i << "     ";
			for (j = 0; j < G.size(); ++j)
				if (G.is_edge(i, j))
					cout << "   " << j;
			cout << endl;
		}
		cout << endl;
		for (i = 0; i < G.size(); ++i)
		{
			cout << "Depth-First Traversal of Trees on Graph "
				<< "starting with Vertex " << i << endl;
			G.tree_level(i, 0);
		}

	}
	else
	{
		cout << "Invalid input for number of vertices. "
			<< "Program terminating." << endl;
	}
	return 0;
} 

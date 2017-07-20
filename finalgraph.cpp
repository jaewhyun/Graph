//
//  finalgraph.cpp
//  finalgraph
//
//  Created by Jae Won Hyun on 12/21/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include "finalgraph.h"
#include <iostream>
using namespace std;

// function for adding vertexes
void Graph::add_vertexes (const int nr)
{
    count_of_vertices = nr;
    for (x = 0; x < nr; ++x)
        for (y = 0; y < nr; ++y)
            edge[x][y] = false;
}

// function for retrieving the number of vertexes
int Graph::get_vertexes()
{
    return count_of_vertices;
}

// adding an edge
void Graph::add_edge()
{
    cout << "Enter the two bounding vertexes of an edge " << endl;
    int source, target;
    
    cin >> source >> target;
    
    if (!cin.eof() && cin.good() && source < count_of_vertices && target < count_of_vertices && source < target)
    {
        edge[source][target] = true;
        ++x;
    }
    else
    {
        if (!cin.eof() && cin.good()) {
            if (source >= target)
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

// deleting an edge
void Graph::delete_edge()
{
    cout << "Enter the two bounding vertexes of an edge that you would like to delete" << endl;
    int source, target;
    
    cin >> source >> target;
    
    if (!cin.eof() && cin.good() && source < count_of_vertices && target < count_of_vertices && source < target)
    {
        edge[source][target] = false;
        --x;
    }
    else
    {
        if (!cin.eof() && cin.good()) {
            if (source >= target)
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

// returning the edge
bool Graph::is_edge(int source, int target) const
{
    return edge[source][target];
}

// traversing
void Graph::tree_level (int x, int level)
{
    int j, i;
    
    ++level;
    
    for (j = 0; j < size(); ++j)
    {
        if (is_edge (x, j))
        {
            for (i = 1; i < level ; cout << "   ", ++i)
            {
              cout << "  (" << x << ", " << j << ")" << endl;
                if ( x != j )
                    tree_level (j, level);
            }

        }
    }
}

// displaying adjacency matrix
void Graph::displayAdjacencyMatrix(int nr)
{
    cout << endl << "Adjacency Matrix"
    << " -- e signifies an Edge in your Graph" << endl;
    for(int x = 0; x < nr; x++)
    {
        cout << " " << x << endl;
    }
    
    char dispEdge[MAX];
    
    for (int x = 0; x < nr; x++)
    {
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

// getting directedlist
void Graph::directedlist()
{
    cout << "From which vertex would you like to see the directed list of neighbor vertexes? ";
    int vertexinput;
    cin >> vertexinput;
    
    if(!cin.eof() && cin.good())
    {
        cout << "For Vertex " << vertexinput << "     ";
        
        for (int j = 0; j < count_of_vertices; ++j)
        {
            if (is_edge(vertexinput, j))
                cout << "   " << j;
        }
        
        cout << endl;
    }
    
    cout << endl;
}

// display depth
void Graph::displaydepthfirst()
{
    cout << "Which vertex would you like to traverse from?";
    int vertexinput;
    cin >> vertexinput;
    
    if(!cin.eof() && cin.good())
    {
        for(int i = vertexinput; i < count_of_vertices; i++)
        {
            cout << "Depth-First Traversal of Trees on Graph "
            << "starting with Vertex " << i << endl;
            tree_level(i, 0);
        }
    }
    else
    {
        cout << "Invalid input. Program exiting." << endl;
        exit(1);
    }
}

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
#include "finalgraph.h"
using namespace std;

int main ()
{
    // declare object
    Graph G;
    // declare int nr
    int nr;
    
    // get userinput of the number of vertexes
    cout << "Enter number of vertices (1 < nr <= 100) ";
    cin >> nr;
    // if the number of vertexes is a good input
    if(!cin.eof() && cin.good())
    {
        // add vertexes
        G.add_vertexes(nr);
    }
    // otherwise exit
    else
    {
        cout << "Invalid input for number of vertices. "
        << "Program terminating." << endl;
        return 0;
    }
    
    // alert the user of the limits
    cout << "Number of vertices is " << G.get_vertexes() << endl;
    cout << " Numbers of Beginning and Terminating vertexes must be between 0 and "
    << (nr - 1) << " inclusive" << endl;
    cout << "Number of Beginning vertex must be less than that of Terminating vertex."
    << endl;
    
    // if the user input is within range
    if (!cin.eof() && cin.good() && nr >= 2 && nr <= MAX)
    {
        // clear the input
        cin.clear();
        
        // set true value
        bool cont = true;
        
        // set decision
        char decision;
        
        // while it's not the end of the input
        while(!cin.eof() && cont == true)
        {
            // help
            cout << "\nE - add edge into A.M.\n";
            cout << "D - delete edge from A.M.\n";
            cout << "M - Display A.M.\n";
            cout << "N - Display Directed List of Neighbor Vertexes from a spec. vertex\n";
            cout << "T - Display Depth-first Traversal through the Graph from a spec. vertex\n";
            cout << "what would you like to do?: ";
            cin >> decision;
            
            // while the decision input is not the end
            if(!cin.eof())
            {
                switch(decision)
                {
                    // add edge
                    case 'A': case 'a': {
                        if (!cin.eof())
                        {
                            G.add_edge();
                        }
                        break;
                    }
                    // delete edge
                    case 'D': case 'd': {
                        if (!cin.eof())
                        {
                            G.delete_edge();
                        }
                        break;
                    }
                    // display matrix
                    case 'M': case 'm': {
                        if (!cin.eof())
                        {
                            G.displayAdjacencyMatrix(nr);
                        }
                        break;
                    }
                    // get directed list of neighbor vertexes
                    case 'N': case 'n':{
                        if(!cin.eof())
                        {
                            G.directedlist();
                        }
                        break;
                    }
                    // display depth first traversal
                    case 'T': case 't': {
                        if (!cin.eof())
                        {
                            G.displaydepthfirst();
                        }
                        break;
                    }
                    // exit program
                    case 'E': case 'e': {
                        cout << "Ending program..." << endl;
                        exit(1);
                    }
                    // default
                    default: {
                        cout << "Invalid function entered." << endl;
                        break;
                    }
                }
                
            }
        }
    }

}

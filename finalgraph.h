//
//  finalgraph.h
//  finalgraph
//
//  Created by Jae Won Hyun on 12/21/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#ifndef finalgraph_h
#define finalgraph_h

#include <stdio.h>

const int MAX = 100;

class Graph {
private:
    bool edge [MAX][MAX];
    int count_of_vertices;
    int vflag [MAX];
    int x;
    int y;
    
public:
    const int MAX = 100;
    Graph () { count_of_vertices = 0; }
    int size () const {return count_of_vertices; }
    
    void add_vertexes (const int);
    int get_vertexes();
    void add_edge ();
    void delete_edge();
    void directedlist();
    bool get_edge (int a, int b) { return edge [a][b]; }
    bool is_edge (int source, int target) const;
    void tree_level (int, int);
    void clear_vflags(int);
    void clear_vflag(int);
    void set_vflag(int);
    int  test_vflag(int);
    void displayAdjacencyMatrix(int);
    void displaydepthfirst();
};

#endif /* finalgraph_h */

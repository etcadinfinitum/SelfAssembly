#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <cassert>

using namespace std;

// forward declarations
bool createEmptyGraph();
bool createNonEmptyGraphFromFile();
bool createNonEmptyGraphFromBoutiqueVertices();

int main() {
    assert(createEmptyGraph());
    assert(createNonEmptyGraphFromFile());
    assert(createNonEmptyGraphFromBoutiqueVertices());
    return 0;
}

bool createEmptyGraph() {
    Graph g;
    return true;
}

bool createNonEmptyGraphFromFile() {
    Graph g;
    assert(g.import("graph_schemas/cycleThree.txt"));
    return true;
}

bool createNonEmptyGraphFromBoutiqueVertices() {
    Graph g;
    Vertex* v1 = new Vertex();
    v1->setName("1");       // fully optional
    Vertex* v2 = new Vertex();
    Vertex* v3 = new Vertex();
    Vertex* v4 = new Vertex();
    Vertex* v5 = new Vertex();
    Vertex* v6 = new Vertex();
    assert(g.join(v1, v2));
    assert(!g.separate(v2, v3));
    assert(g.join(v2, v3));
    assert(!g.join(v2, v3)); // duplicate edges are enforced by operator== overload for Edge. 
                            // 
    assert(g.separate(v2, v3));
    assert(!g.separate(v2, v3));
    delete v4;
    delete v5;
    delete v6;
    return true;
}

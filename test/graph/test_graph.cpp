#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <cassert>

using namespace std;

// forward declarations
bool createEmptyGraph();
bool createNonEmptyGraphFromFile();
bool createNonEmptyGraphFromBoutiqueVertices();
bool testCopyAssignment();
bool testCopyConstructor();

int main() {
    assert(createEmptyGraph());
    assert(createNonEmptyGraphFromFile());
    assert(createNonEmptyGraphFromBoutiqueVertices());
    assert(testCopyAssignment());
    assert(testCopyConstructor());
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
    cout << "Testing graph construction using join()/separate()...\n";
    Graph g;
    shared_ptr<Vertex> v1 = make_shared<Vertex>("a");
    shared_ptr<Vertex> v2 = make_shared<Vertex>("b");
    shared_ptr<Vertex> v3 = make_shared<Vertex>("c");
    cout << "Join v1 and v2 (a, b)..." << endl;
    assert(g.join(v1, v2));
    cout << "Sep v2 and v3 (b, c) (should fail)" << endl;
    assert(!g.separate(v2, v3));
    cout << "Join v2 and v3 (b, c)..." << endl;
    assert(g.join(v2, v3));
    cout << "Join v2 and v3 (b, c) (should fail)..." << endl;
    assert(!g.join(v2, v3));     // duplicate edges should be detected with comparison overload for Edge. 
    cout << "Sep v2 and v3 (b, c) (should succeed)..." << endl;
    assert(g.separate(v2, v3));
    cout << "Sep v2 and v3 (b, c) (should fail)..." << endl;
    assert(!g.separate(v2, v3));
    cout << "Final graph: \n" << g << endl;
    cout << endl;
    return true;
}

bool testCopyAssignment() {
    cout << "Testing copy assignment...\n";
    Graph g;
    assert(g.import("graph_schemas/cycleThree.txt"));
    Graph h;
    h = g;
    assert(&g != &h);
    cout << "Graph g: \n" << g;
    cout << "Graph h: \n" << h;
    cout << endl;
    return true;
}

bool testCopyConstructor() {
    cout << "Testing copy constructor...\n";
    Graph g;
    assert(g.import("graph_schemas/cycleThree.txt"));
    Graph h(g);
    assert(&g != &h);
    cout << "Graph g: \n" << g;
    cout << "Graph h: \n" << h;
    cout << endl;
    return true;
}

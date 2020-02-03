#include "Edge.h"
#include "Vertex.h"
#include <cassert>

using namespace std;

// forward declarations
bool testCreation();
bool testEquality();

int main() {
    assert(testCreation());
    assert(testEquality());
    return 0;
}

bool testCreation() {
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Edge* e1 = new Edge(v1, v2, false);
    assert(e1->getFirst() == v1);
    assert(e1->getSecond() == v2);
    delete e1;
    delete v1;
    delete v2;
    return true;
}

bool testEquality() {
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Vertex* v3 = new Vertex();
    Edge* e1 = new Edge(v1, v2, false);
    Edge* e2 = new Edge(v2, v1, false);
    Edge* e3 = new Edge(v1, v3, false);
    Edge* e4 = new Edge(v3, v1, false);
    assert(*e1 == *e2);
    assert(*e1 == *e1);
    assert(!(*e2 == *e3));
    assert(*e3 == *e4);
    assert(!(*e1 == *e3));
    delete v1;
    delete v2;
    delete v3;
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    return true;
}

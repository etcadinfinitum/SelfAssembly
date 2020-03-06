#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "Rule.h"
#include <cassert>

using namespace std;

// forward declarations
bool testRuleCreation();
bool testVertexAdd();
bool testGetRHSLHSGraphs();

int main() {
    assert(testRuleCreation());
    assert(testGetRHSLHSGraphs());
    assert(testVertexAdd());
    return 0;
}

bool testRuleCreation() {
    Rule r;
    Rule* heap = new Rule();
    delete heap;
    return true;
}

bool testGetRHSLHSGraphs() {
    Rule* r = new Rule();
    Graph* lhs = r->getLeftGraph();
    Graph* rhs = r->getRightGraph();
    assert(lhs != nullptr);
    assert(rhs != nullptr);
    // TODO: assert vertex size for both is 0
    delete r;
    return true;
}

bool testVertexAdd() {
    Rule* r = new Rule();
    shared_ptr<Vertex> v1 = make_shared<Vertex>("a");
    assert(r->addVertex(v1, "a", "b"));
    Graph* lhs = r->getLeftGraph();
    Graph* rhs = r->getRightGraph();
    assert(lhs != nullptr);
    assert(rhs != nullptr);
    assert(lhs->containsVertex(v1));
    assert(rhs->containsVertex(v1));
    delete r;
    return true;
}

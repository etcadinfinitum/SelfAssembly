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
bool testLeftVertexJoin();

int main() {
    assert(testRuleCreation());
    assert(testGetRHSLHSGraphs());
    assert(testVertexAdd());
    assert(testLeftVertexJoin());
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

bool testLeftVertexJoin() {
    Rule* r = new Rule();
    shared_ptr<Vertex> v1 = make_shared<Vertex>("a");
    shared_ptr<Vertex> v2 = make_shared<Vertex>("b");
    shared_ptr<Edge> e = make_shared<Edge>(v1, v2);
    assert(r->addVertex(v1, "a", "b"));
    // NOTE: the fact that addVertex(v2) was not called presents an 
    // interesting problem for rule completeness. There are a few potential 
    // routes for refactoring this:
    // 1) Require all parameters for Join operations (labels included)
    // 2) Perform a completeness check at the end of a specific operation:
    //    a) at the beginning or end of the join() call for rules
    //    b) in the operator<< function
    // Solution is forthcoming...
    assert(!(r->lhsJoin(v1, v1)));
    assert(r->lhsJoin(v1, v2));
    assert(!(r->lhsJoin(v1, v2)));
    Graph* lhs = r->getLeftGraph();
    assert(lhs != nullptr);
    assert(lhs->containsVertex(v1));
    assert(lhs->containsVertex(v2));
    assert(lhs->containsEdge(e));
    delete r;
    return true;
}

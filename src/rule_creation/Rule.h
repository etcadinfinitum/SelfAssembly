#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <utility>      // std::pair
#include <vector>
#include <iostream>

using namespace std;

class Rule {
    private:
        Graph* initialState = nullptr;
        Graph* finalState = nullptr;
        // necessary to ensure state preservation of labels for vertices; label 
        // member of Vertex* will change throughout call stack
        vector<pair<shared_ptr<Vertex> vertex, pair<string, string> lhsToRhs>*>* labelData;
        
    public:
        Rule();
        ~Rule();
        friend ostream& operator<<(ostream&, const Rule&);
        // TODO: is equality comparison needed?
        // friend bool operator==(const Rule&, const Rule&);
        bool addVertex(shared_ptr<Vertex> v, string lhsLabel, string rhsLabel);
        bool lhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2);
        bool rhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2);
        
};

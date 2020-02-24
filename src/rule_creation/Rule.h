#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <utility>      // std::pair
#include <vector>
#include <iostream>

using namespace std;

class Rule {
    private:
        // TODO: is this the best way to describe a rule?
        Graph* initialState = nullptr;
        Graph* finalState = nullptr;
        // TODO: is this a better alternate?
        // for each v: pair.first is old label, pair.second is new
        vector<pair<string, string>*>* labels = nullptr;
        
    public:
        friend ostream& operator<<(ostream&, const Rule&);
        friend bool operator==(const Rule&, const Rule&);
        
};

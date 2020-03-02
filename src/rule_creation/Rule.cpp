#include "Rule.h"

using namespace std;

/**
 * Basic constructor; all objects are allocated on the heap and 
 * are initially empty.
 */
Rule::Rule() {
    this->initialState = new Graph();
    this->finalState = new Graph();
    this->labelData = new vector<pair<shared_ptr<Vertex>, pair<string, string>>*>();
}

/**
 * Basic destructor; delete member graphs and deallocate vector 
 * entries.
 */
Rule::~Rule() {
    delete this->initialState;
    delete this->finalState;
    vector<pair<shared_ptr<Vertex>, pair<string, string>>>::iterator it;
    for (it = this->labelData->begin(); it != this->labelData->end(); ++it) {
        delete *it;
    }
}

/**
 * String representation of rules is required for manual confirmation 
 * of rule correctness, as well as consumption by code generator. 
 *
 * Rule representation may change based on researcher's need 
 * or representation complexity; this will be a work in progress 
 * until further notice.
 */
ostream& operator<<(ostream& out, const Rule& rule) {
    // TODO: implement
    return out;
}

/*
bool operator==(const Rule& lhs, const Rule& rhs) {
    return false;
}
*/

/**
 * Method which adds vertex and label assignment to rule; core 
 * component of state preservation of rules.
 */
bool addVertex(shared_ptr<Vertex> v, string lhsLabel, string rhsLabel) {
    // TODO: implement
    // Add vertex to both LHS and RHS graph if not already present
    // Add vertex to labelData vector if not already present
    // If present, need to determine how this should be handled.
    return false;
}

/**
 * Method which forms edges in LHS graph representation; core 
 * component of rule type & purpose.
 */
bool lhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) {
    // TODO: implement
    // call initialState->join(v1, v2) and return result
    return false;
}

/**
 * Method which forms edges in RHS graph representation; core 
 * component of rule type & purpose.
 */
bool rhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) {
    // TODO: implement
    // call finalState->join(v1, v2) and return result
    return false;
}

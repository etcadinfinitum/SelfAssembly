#include "Rule.h"

using namespace std;

/**
 * Basic constructor; all objects are allocated on the heap and 
 * are initially empty.
 */
Rule::Rule() {
    this->initialState = new Graph();
    this->finalState = new Graph();
    this->labelData = new vector<pair<shared_ptr<Vertex>, pair<string, string>*>*>();
}

/**
 * Basic destructor; delete member graphs and deallocate vector 
 * entries.
 */
Rule::~Rule() {
    delete this->initialState;
    delete this->finalState;
    vector<pair<shared_ptr<Vertex>, pair<string, string>*>*>::iterator it;
    for (it = this->labelData->begin(); it != this->labelData->end(); ++it) {
        delete (*it)->second;
        delete *it;
    }
    delete labelData;
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
bool Rule::addVertex(shared_ptr<Vertex> v, string lhsLabel, string rhsLabel) {
    // Add vertex to both LHS and RHS graph if not already present
    this->initialState->addVertex(v);
    this->finalState->addVertex(v);
    // Add vertex to labelData vector if not already present
    vector<pair<shared_ptr<Vertex>, pair<string, string>*>*>::iterator it;
    for (it = this->labelData->begin(); it != this->labelData->end(); ++it) {
        // return false if present already (for now)
        if ((*it)->first == v) return false;
    }
    pair<string, string>* labels = new pair<string, string>(lhsLabel, rhsLabel);
    pair<shared_ptr<Vertex>, pair<string, string>*>* node = new pair<shared_ptr<Vertex>, pair<string, string>*>(v, labels);
    this->labelData->insert(this->labelData->begin(), node);
    return true;
}

bool Rule::confirmLabelDataForVertexJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) {
    bool hasV1 = false;
    bool hasV2 = false;
    // check for v1 and v2 in labelData set
    vector<pair<shared_ptr<Vertex>, pair<string, string>*>*>::iterator it;
    for (it = this->labelData->begin(); it != this->labelData->end(); ++it) {
        // return false if present already (for now)
        if (*((*it)->first) == *(v1.get())) hasV1 = true;
        if (*((*it)->first) == *(v2.get())) hasV2 = true;
    }
    if (!hasV1) {
        cerr << "WARNING: label data for v1 with name " << v1.get()->getName()
             << " is not in labelData set." << endl;
    }
    if (!hasV1) {
        cerr << "WARNING: label data for v2 with name " << v2.get()->getName()
             << " is not in labelData set." << endl;
    }
    return hasV1 && hasV2;
}

/**
 * Method which forms edges in LHS graph representation; core 
 * component of rule type & purpose.
 */
bool Rule::lhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) {
    if (!this->confirmLabelDataForVertexJoin(v1, v2)) return false;
    // call initialState->join(v1, v2) and return result
    return this->initialState->join(v1, v2);
}

/**
 * Method which forms edges in RHS graph representation; core 
 * component of rule type & purpose.
 */
bool Rule::rhsJoin(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) {
    // TODO: implement
    // call finalState->join(v1, v2) and return result
    return false;
}

Graph* Rule::getLeftGraph() {
    return this->initialState;
}

Graph* Rule::getRightGraph() {
    return this->finalState;
}

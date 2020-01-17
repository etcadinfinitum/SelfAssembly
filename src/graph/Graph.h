#include <set>
#include <string>
#include <iostream>

using namespace std;

class Graph {
    private:
        // TODO: best structure for edges?
        // TODO: should this be reflexive?
        set<pair<Vertex*, Vertex*>>* edges;
        set<Vertex*>* vertices;
    public:
        Graph();
        ~Graph();
        bool import(string filename);
        bool join(Vertex*, Vertex*);
        bool separate(Vertex*, Vertex*);
        // TODO: operator overload for copy, ostream
};

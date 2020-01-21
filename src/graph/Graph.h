#include <set>
#include <string>
#include <iostream>

using namespace std;

class Graph {
    private:
        set<Edge*>* edges;
        set<Vertex*>* vertices;
    public:
        Graph();
        ~Graph();
        bool import(string filename);
        bool join(Vertex*, Vertex*);
        bool separate(Vertex*, Vertex*);
        // TODO: operator overload for copy, ostream
};

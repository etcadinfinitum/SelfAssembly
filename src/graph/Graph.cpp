#include <utility>  // std::pair, std::make_pair
#include <string>
#include <set>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

Graph::Graph() {
    this.edges = new set<Edge*>();
    this.vertices = new set<Vertex*>();
}

Graph::~Graph() {
    // TODO: iterate over sets, deleting pairs
    delete edges;
    delete vertices;
}

/**
 * A utility method for building a partially-connected 
 * graph based on a schematic described in a text file.
 *
 * The current implementation requires the text file 
 * to contain delimited pairs of vertices, one per line.
 * The default delimiter is '*'.
 *
 * The vertices are expected to be uniquely named, and 
 * when constructing edges, existing vertices will be 
 * searched for a matching name before creating a new 
 * vertex.
 *
 * For example, a text file could contain the following 
 * contents:
 * A * X
 * X * Y
 * Y * A
 * This schematic constructs a 3-node cycle.
 */
bool Graph::import(string filename) {
    string line;
    ifstream graphFile(filename);
    if (graphFile.is_open()) {
        while (getline(graphFile, line)) {
            // TODO: split line by edge delimiter
            // TODO: search for vertices by name
            // TODO: if v doesn't exist, create it
            // TODO: create new pair
            cout << line << '\n';
        }
        myfile.close();
    } else { 
        cout << "Unable to open file";
        return false;
    }
    return true;
}

bool Graph::join(Vertex* a, Vertex* b) {
    if (a == nullptr || b == nullptr) {
        cerr << "Graph::join(): One or both of the"
             << " vertices are nullptrs." << endl;
        return false;
    }
    edges->add(make_pair(a, b));
    edges->add(make_pair(b, a));
    return true;
}

bool Graph::separate(Vertex* a, Vertex* b) {
    // TODO
    return false;
}

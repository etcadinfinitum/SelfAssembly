using namespace std;

Vertex::Vertex() {
    this.label = "";
    this.name = "";
}

Vertex::~Vertex() {
}

bool Vertex::setLabel(string l) {
    this.label = l;
}

bool Vertex::setName(string name) {
    this.name = name;
}

string Vertex::getName() {
    return this.name;
}

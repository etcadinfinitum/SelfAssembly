using namespace std;

Vertex::Vertex() {
    this.label = "";
}

Vertex::~Vertex() {
}

bool Vertex::setLabel(string l) {
    this.label = l;
}

bool Vertex::setName(string name) {
    this.name = name;
}

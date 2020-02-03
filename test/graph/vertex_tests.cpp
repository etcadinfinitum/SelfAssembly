#include "Vertex.h"
#include <cassert>

using namespace std;

// forward declarations
bool testCreationAndRenaming();

int main() {
    assert(testCreationAndRenaming());
    return 0;
}

bool testCreationAndRenaming() {
    Vertex* v1 = new Vertex();
    assert(v1->getName() == "");
    assert(v1->getLabel() == "");
    v1->setName("myName");
    assert(v1->getName() == "myName");
    v1->setLabel("myLabel");
    assert(v1->getLabel() == "myLabel");
    delete v1;
    return true;
}

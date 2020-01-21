#include <string>
#include <iostream>

using namespace std;

class Vertex {
    private:
        string label;
        string name;
    public:
        Vertex();
        ~Vertex();
        bool setLabel(string);
        bool setName(string);
        string getName();
};

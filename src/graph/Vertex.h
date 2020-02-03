#include <string>

using namespace std;

#ifndef VERTEX_H__
#define VERTEX_H__

class Vertex {
    private:
        string label;
        string name;
    public:
        Vertex();
        ~Vertex();
        void setLabel(string);
        void setName(string);
        string getName();
        string getLabel();
        friend bool operator==(const Vertex&, const Vertex&);
};

#endif          // VERTEX_H__

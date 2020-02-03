#!/bin/bash

g++ -o test -I../../src/graph -I. ../../src/graph/Vertex.cpp test_vertex.cpp

./test
valgrind ./test
rm test

g++ -o test -I../../src/graph -I. ../../src/graph/Edge.cpp ../../src/graph/Vertex.cpp test_edge.cpp
./test
valgrind ./test
rm test

g++ -o test -I../../src/graph -I. ../../src/graph/Graph.cpp ../../src/graph/Edge.cpp ../../src/graph/Vertex.cpp test_graph.cpp 

./test
valgrind ./test
rm test

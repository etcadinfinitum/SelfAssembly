#!/bin/bash

g++ -o test -I../../src/graph -I. ../../src/graph/Vertex.cpp vertex_tests.cpp

./test
valgrind ./test
rm test

g++ -o test -I../../src/graph -I. ../../src/graph/Graph.cpp ../../src/graph/Edge.cpp ../../src/graph/Vertex.cpp graph_tests.cpp 

./test
valgrind ./test
rm test

#pragma one

#include<iostream>
#include<stdexcept>
#include<fstream>
#include"linked_list.h"

template<typename T>
class GraphType {

    friend std::ostream& operator<<(std::ostream& out, const GraphType<T>& graph) {

        for (int i{0}; i < graph.g_size; i++) {
            out << i << "(" << graph.vertices[i] << ") -> ";
            out << graph.adjacencyLists[i];
        }
        return out;
    }

public:
    // constructors
    GraphType() 
        : max_size{50}, g_size{0}, vertices{new T[max_size]}, adjacencyLists{new LinkedList<int>[max_size]} {
            // empty list
        }

    explicit GraphType(size_t max_size) 
        : max_size{max_size}, g_size{0}, vertices{new T[max_size]}, adjacencyLists{new LinkedList<int>[max_size]} {
            // empty body
        }

    // destructor
    ~GraphType() {

        // deallocate the all the dynamically allocated object types
        delete [] vertices;
        clear();
        delete [] adjacencyLists;
    }

    void clear() {

        for (int i = 0; i < g_size; i++) {
            adjacencyLists[i].destroy_list(); // deallocate the memory of the adjcency lists
        }
        g_size = 0; // set the graph size as zero

    }

    bool empty() const {
        return g_size == 0;
    }

    // function to load the graph froma file
    void load(const char* fileName) {

        // if graph is not empty clear the graph
        if (!empty()) clear();
        // create an input file stream
        std::ifstream infile{fileName, std::ios::in};

        // check whether file opens successfully
        if (!infile) {
            throw std::invalid_argument("file is not found");
        }

        T vertex;
        int adjacencyVertexIndex;

        infile >> g_size;
        for (int i{0}; i < g_size; i++) {

            // read the first vertex of the adjacency list
            infile >> vertex;
            infile >> adjacencyVertexIndex;

            vertices[i] = vertex;
            while (adjacencyVertexIndex != -1) {

                adjacencyLists[i].insert_last(adjacencyVertexIndex);
                infile >> adjacencyVertexIndex; 

            } // end of whilw
        } // end of for
        // close the file stream
        infile.close();

    }



private:

    size_t max_size;    // maximum number of nodes graph hold
    size_t g_size; // current graph size - number of current nodes
    T *vertices; // vertices data array
    LinkedList<int>* adjacencyLists;  // array of adjacancy list of arrays

};
#pragma one

#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<fstream>
#include<queue>
#include"linked_list.h"

typedef LinkedList<int>::iterator iterator;

template<typename T>
struct Vertex {
    // structure for store the vertex actual data and addtional data needed by the graph algorithms
    T data;
    // addiotional fields for implement the traversal algorithms
    char color; // color to identify the nodes whether nodes are discovered, reached out or finished
    int distance;   // distance from the source vertex;
    Vertex<T> *parent; // parent vertex pointer which adjacent to the current vertex
};

template<typename T>
class GraphType {

    friend std::ostream& operator<<(std::ostream& out, const GraphType<T>& graph) {

        for (int i{0}; i < graph.g_size; i++) {
            out << i << "(" << graph.vertices[i].data << ") -> ";
            out << graph.adjacencyLists[i];
        }
        return out;
    }

public:
    // constructors
    GraphType() 
        : max_size{50}, g_size{0}, vertices{new Vertex<T>[max_size]}, adjacencyLists{new LinkedList<int>[max_size]} {
            // empty list
        }

    explicit GraphType(size_t max_size) 
        : max_size{max_size}, g_size{0}, vertices{new Vertex<T>[max_size]}, adjacencyLists{new LinkedList<int>[max_size]} {
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

            vertices[i] = {vertex};
            while (adjacencyVertexIndex != -1) {

                adjacencyLists[i].insert_last(adjacencyVertexIndex);
                infile >> adjacencyVertexIndex; 

            } // end of whilw
        } // end of for
        // close the file stream
        infile.close();

    }

    // traversal algorithms for graphs
    void BFS(const T& source) {
        int source_index = find_index(source);
        // mark all the vertex as white, distance as zero and parent to null 
        for (int i{0}; i < g_size; i++) {
            vertices[i].color = 'w'; // indicate that this vertex is not yet discovered
            vertices[i].distance = -1; // indicate that distance from the source is not set
            vertices[i].parent = nullptr;
        }
        vertices[source_index].color = 'g';
        vertices[source_index].distance = 0;
        std::queue<int> queue;
        queue.push(source_index);
        // run the while loop until queue is empty
        while (!queue.empty()) {
            int vertex_index = queue.front();
            queue.pop();
            for (iterator iter = adjacencyLists[vertex_index].begin(); iter != adjacencyLists[vertex_index].end(); ++iter) {
                if (vertices[*iter].color == 'w') {
                    vertices[*iter].color = 'g';
                    vertices[*iter].distance = vertices[vertex_index].distance + 1;
                    vertices[*iter].parent = (vertices + vertex_index);
                    // enquee into the queue
                    queue.push(*iter);
                }
            }
            // mark the vertex as finished
            vertices[vertex_index].color = 'b';
        }
    }

    void bfs_result() const {

        std::cout << std::left << std::setw(10) << "Index" << std::setw(15) << "Vertex"
                << std::setw(10) << "Distance" << std::endl;
        for (int i{0}; i < g_size; i++) {
            std::cout << std::left << std::setw(10) << i << std::setw(15) << vertices[i].data
                    << std::setw(10) << vertices[i].distance << std::endl;
        }

    }

private:

    // helper function for find the index of the given vertex data
    int find_index(const T& data) const {
        for (int i{0}; i < g_size; i++) {
            if (vertices[i].data == data) {
                return i;
            }
        }
        return -1; // indicate that the given data is not found
    }


    size_t max_size;    // maximum number of nodes graph hold
    size_t g_size; // current graph size - number of current nodes
    Vertex<T> *vertices; // vertices data array
    LinkedList<int>* adjacencyLists;  // array of adjacancy list of arrays

};
#pragma one

#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<fstream>
#include<queue>
#include"linked_list.h"

typedef LinkedList<int>::iterator iterator;

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

    size_t size() const {
        return g_size;
    }

    LinkedList<int>& adjacencyList(int adj_index) {
        return adjacencyLists[adj_index];
    }

    const T* get_vertices() const {
        return vertices;
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

    // helper function for find the index of the given vertex data
    int find_index(const T& data) const {
        for (int i{0}; i < g_size; i++) {
            if (vertices[i] == data) {
                return i;
            }
        }
        return -1; // indicate that the given data is not found
    }

private:

protected:
    size_t max_size;    // maximum number of nodes graph hold
    size_t g_size; // current graph size - number of current nodes
    T *vertices; // vertices data array
    LinkedList<int>* adjacencyLists;  // array of adjacancy list of arrays

};

// wrapper class for implement the BFS traversal on top of the graph
template<typename T>
class Wr_BFS {
public:
    // there is no default constructor for this class
    Wr_BFS() = delete;
    // explicit one argument constructor
    explicit Wr_BFS(GraphType<T>& graph) : graph(graph), bfs_set{new BFSData[graph.size()]} {
        // fill the BFS data with deafult values
        for (int i{0}; i < graph.size(); i++) {
            bfs_set[i] = {'w', -1, -1};
        }
    }

    // BFS traversal algorithm
    // traversal algorithms for graphs
    void BFS(const T& source) {
        int source_index = graph.find_index(source);
        
        bfs_set[source_index].color = 'g';
        bfs_set[source_index].distance = 0;
        std::queue<int> queue;
        queue.push(source_index);
        // run the while loop until queue is empty
        while (!queue.empty()) {
            int vertex_index = queue.front();
            queue.pop();
            for (iterator iter = graph.adjacencyList(vertex_index).begin(); iter != graph.adjacencyList(vertex_index).end(); ++iter) {
                if (bfs_set[*iter].color == 'w') {
                    bfs_set[*iter].color = 'g';
                    bfs_set[*iter].distance = bfs_set[vertex_index].distance + 1;
                    bfs_set[*iter].parent = vertex_index;
                    // enquee into the queue
                    queue.push(*iter);
                }
            }
            // mark the vertex as finished
            bfs_set[vertex_index].color = 'b';
        }
    }

    void result(bool with_trace = false) const {

        std::cout << std::left << std::setw(10) << "Index" << std::setw(15) << "Vertex"
                << std::setw(15) << "Parent" << std::setw(10) << "Distance";
        if (with_trace) {
            std::cout << "Trace";
        }
        std::cout << std::endl;

        for (int i{0}; i < graph.size(); i++) {
            if (bfs_set[i].parent == -1) {
                std::cout << std::left << std::setw(10) << i << std::setw(15) 
                    << graph.get_vertices()[i] << std::setw(15) << "null"
                    << std::setw(10) << bfs_set[i].distance;
            } else {
                std::cout << std::left << std::setw(10) << i << std::setw(15) 
                    << graph.get_vertices()[i] << std::setw(15) << graph.get_vertices()[bfs_set[i].parent]
                    << std::setw(10) << bfs_set[i].distance;
            }

            if (with_trace) {
                trace(i);
            }
            std::cout << std::endl;
        }

    }

    void trace(int v_index) const {
        // traverse through the predeccessor graph of the given vertex index
        // recursively print the predeccessor graph in the console until source is found
        if (bfs_set[v_index].parent == -1) {
            std::cout << v_index;
        } else {
            trace(bfs_set[v_index].parent);
            std::cout << " -> " << v_index;
        }
    }


private:

    struct BFSData
    {
        // structure for store the color, parent and the distance from the source to the each nodes
        char color;
        int parent;
        int distance; // distance from the source to the current node
    } *bfs_set;

    GraphType<T>& graph;
    

};


// wrapper class for implement the DFS traversal on top of the graph
template<typename T>
class Wr_DFS {
public:
    // there is not deafult constructor for Wr_DFS 
    Wr_DFS() = delete;
    // explicit one argument constructor    
    explicit Wr_DFS(GraphType<T>& graph) : dfs_set{new DFSData[graph.size()]}, graph(graph) {
        // fill the dfs set with the default values
        for (int i{0}; i < graph.size(); i++) {
            dfs_set[i] = {-1, -1, -1, 'w'};
        }
    }

    ~Wr_DFS() {
        // deallocate the dynamically allocated dfs data array
        delete [] dfs_set;
    }

    // implement the algorithm
    void DFS() {

        g_time = 0; // reset the global timer
        for (int i{0}; i < graph.size(); i++) {
            if (dfs_set[i].color == 'w') {
                dfs_helper(i);
            }
        }

    }

    void result(bool with_trace = false) const {

        std::cout << std::left << std::setw(7) << "Index" << std::setw(15) << "Vertex"
                    << std::setw(15) << "Parent" << std::setw(8) << "Start" << std::setw(8)
                    << "End";
        if (with_trace) {
            std::cout << "Trace";
        }
        std::cout << std::endl;

        for (int i{0}; i < graph.size(); i++) {
            if (dfs_set[i].parent == -1) {
                std::cout << std::setw(7) << i << std::setw(15) << graph.get_vertices()[i]
                    << std::setw(15) << "null"
                    << std::setw(8) << dfs_set[i].s_time << std::setw(8)
                    << dfs_set[i].f_time;
            } else {
                std::cout << std::setw(7) << i << std::setw(15) << graph.get_vertices()[i]
                    << std::setw(15) << graph.get_vertices()[dfs_set[i].parent]
                    << std::setw(8) << dfs_set[i].s_time << std::setw(8)
                    << dfs_set[i].f_time;
            }

            if (with_trace) {
                back_trace(i);
            }
            std::cout << std::endl;
        }

    }

    void back_trace(int v_index) const {

        if (dfs_set[v_index].parent == -1) {
            std::cout << v_index;
        } else {
            back_trace(dfs_set[v_index].parent);
            std::cout << " -> " << v_index;
        }

    }


private:
    // helper function for DFS 
    void dfs_helper(int v_index) {

        g_time++;
        dfs_set[v_index].s_time = g_time; // set the visited time of the vertex
        dfs_set[v_index].color = 'g';
        // traverse through the adjacency list of the source vertex
        for (iterator iter{graph.adjacencyList(v_index).begin()}; iter != graph.adjacencyList(v_index).end(); ++iter) {
            if (dfs_set[*iter].color == 'w') {
                dfs_set[*iter].parent = v_index; // set the parent vertex as the source vertex
                dfs_helper(*iter);
            }
        }
        dfs_set[v_index].color = 'b'; // mark as the finished node
        g_time++; // increase the time by one
        // set the finished time of the source vertex
        dfs_set[v_index].f_time = g_time;

    }

    int g_time{0}; // global timer for keep track of the visited times of each nodes
    // array of DSFData structure for maintain the DSF algorithm specific data
    struct DFSData {
        // structure for store the discovered time, finished time of the graph nodes and parent of each nodes in the graph through the traversal
        int s_time; // discovered time
        int f_time; // finished time
        int parent; // index of the parent node of the vertices array
        char color; // indicate the traversal mode of the node as a color character
    } *dfs_set;

    GraphType<T>& graph;

};
#include<iostream>
#include<iomanip>

using namespace std;

const int SIZE{6};

struct Vertex {

    int key;
    int parent;
    bool finished;
};

// functions prototyoes
void Prims_MST(const int graph[][SIZE], Vertex* vertices, int start);
bool empty(const Vertex* vertices);
int extract_min(Vertex *vertices);
void print_MST(const Vertex* vertices, const int graph[][SIZE]);

int main() {

    // adjacency list reoresentation of the given graph as 2D static array
    int graph[SIZE][SIZE] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    // build the Vertex array of the graoh with associated keya and parents
    Vertex vertices[SIZE];
    // call the prims algorithm
    Prims_MST(graph, vertices, 0);
    print_MST(vertices, graph); 

}

void Prims_MST(const int graph[][SIZE], Vertex *vertices, int start) {

    // initialize the vertices to their defautl values
    for (int i{0}; i < SIZE; i++) {
        vertices[i].key = INT32_MAX;
        vertices[i].parent = -1;
        vertices[i].finished = false;
    }

    // set the start vertex key as zero
    vertices[start].key = 0;
    while (!empty(vertices)) {
        // extract the min value from the available vertices
        int u = extract_min(vertices);
        for (int i{0}; i < SIZE; i++) {
            if (graph[u][i] != 0 && !vertices[i].finished && vertices[i].key > graph[u][i]) {
                vertices[i].key = graph[u][i];
                vertices[i].parent = u;
            }
        }
    }


}

bool empty(const Vertex* vertices) {

    for (int i{0}; i < SIZE; i++) {
        if (!vertices[i].finished) return false;
    }
    return true;

}

int extract_min(Vertex* vertices) {

    int min_vertex_index;
    for (int i{0}; i < SIZE; i++) {
        if (!vertices[i].finished) {
            min_vertex_index = i;
            break;
        }
    }

    for (int i{min_vertex_index}; i < SIZE; i++) {
        if (!vertices[i].finished && vertices[i].key < vertices[min_vertex_index].key) {
            min_vertex_index = i;
        }
    }

    vertices[min_vertex_index].finished = true;
    return min_vertex_index;

}

void print_MST(const Vertex* vertices, const int graph[][SIZE]) {

    cout << left << setw(10) <<  "Edge  :" << left << setw(10) << "Weight" << endl;
    for (int i{0}; i < SIZE; i++) {
        if (vertices[i].parent != -1) {
            cout << vertices[i].parent << " - " << i << setw(10) << " : " << graph[vertices[i].parent][i] << endl; 
        }

    }

}
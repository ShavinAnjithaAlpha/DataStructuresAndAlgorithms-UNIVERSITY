#include<iostream>

using namespace std;
const int N{6};

// struct for store the distance values and parents 
struct Vertex {
    int distance;
    int parent;
    bool status;
};

void initialize_single_source(Vertex* vertices, int source);
void dijkstra(Vertex* vertices, int graph[][N], int source);
void relax(Vertex* vertices, int u, int v, int weight);
void print_distances(const Vertex* vertices, int exclude_node);
void print_trace(const Vertex* vertices, int vertex);
int extract_min(const Vertex* vertices);
bool empty(const Vertex* vertices);

int main() {
    // create vertices array 
    Vertex vertices[N];
    // adjacency list representation of the given graph
    int graph[N][N] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source_node{5}; // starting source node
    dijkstra(vertices, graph, source_node);
    print_distances(vertices, source_node); // print the output of the SSSP



}

void print_distances(const Vertex* vertices, int exclude_vertex) {

    for (int i{0}; i < N; i++) {
        if (i == exclude_vertex) continue;
        cout << "Distance of node" << i << "=" << vertices[i].distance << endl;
        cout << "Path=";
        print_trace(vertices, i);
        cout << endl;
    }

}

void print_trace(const Vertex* vertices, int vertex) {

    cout << vertex << " ";
    if (vertices[vertex].parent != -1) {
        print_trace(vertices, vertices[vertex].parent);
    }

}

void dijkstra(Vertex* vertices, int graph[][N], int source) {

    initialize_single_source(vertices, source);

    while (!empty(vertices)) {
        int u = extract_min(vertices);

        for (int i{0}; i < N; i++) {
            if (graph[u][i] != 0) {
                relax(vertices, u, i, graph[u][i]);
            }
        }
        vertices[u].status = false;
    }

}

// relaxation for the vertices
void relax(Vertex* vertices, int u, int v, int weight) {

    if (vertices[v].distance > vertices[u].distance + weight) {
        vertices[v].distance = vertices[u].distance + weight;
        vertices[v].parent = u;
    }

}

// check whether if the vertices is empty
bool empty(const Vertex* vertices) {

    for (int i{0}; i < N; i++) {
        if (vertices[i].status) return false;
    }
    return true;

}

// function for extract the minimum distance vertex from the uncompleted nodes 
int extract_min(const Vertex* vertices) {

    int min_index;
    int min{INT32_MAX};
    for (int i{0}; i < N; i++) {
        if (vertices[i].status && min > vertices[i].distance) {
            min = vertices[i].distance;
            min_index = i;
        }
    }

    return min_index;

}

void initialize_single_source(Vertex* vertices, int source) {

    for (int i{0}; i < N; i++) {
        vertices[i].distance = INT_MAX; // sett eh distance as maximum value
        vertices[i].parent = -1;
        vertices[i].status = true;
    }

    // set the source distance as zero and parent as NIL
    vertices[source].distance = 0;

}
#pragma one

#include"../graph.h"

typedef LinkedList<Edge>::iterator iterator;

template<typename T>
class MST : public GraphType<T> {
public:
    // constructors
    MST() = delete; // there is no default constructor;
    // explicit constructor
    explicit MST(GraphType<T>& graph) : graph(graph) {
        GraphType<T>(graph.max_size); // initialize the super class
        // fill the vertices class
        for (int i{0}; i < graph.g_size; i++) {
            vertices[i] = graph.get_vertices()[i];
        }
    }

    void buildMST() {

        

    }

    const Edge* addedEdges() const {
        
        Edge* edges = new Edges[g_size];
        for (int i{0}; i < g_size; i++) {
            T value = vertices[i];
            for (iterator it{adjacencyLists[i].begin()}; it != adjacencyLists[i].end(); it++) {
                edges[i] = value;
                edges[*it] = vertices[*it];
            }
        }

        return edges;

    }

    void findLightEdge() {

    }


private:

    GraphType<T>& graph; 

};
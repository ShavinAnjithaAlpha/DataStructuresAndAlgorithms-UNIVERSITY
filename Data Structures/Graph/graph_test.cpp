#include<iostream>
#include"graph.h"

int main() {

    GraphType<int> gr{10};
     // create a graph with maximum 10 vertices
    char fileName[50] = "int_graph.dat";
    // std::cout << "file: ";
    // std::cin.get(fileName, 50);
    
    gr.load(fileName); // load the intgere map data from the data file to the graph
    std::cout << gr; // display the constructed graph
    std::cout << std::endl;

    Wr_BFS<int> bfs(gr);
    bfs.BFS(0);
    bfs.result(true);

    std::cout << std::endl;
    // create a wrapper class for perform the DFS traversal
    Wr_DFS<int> dfs(gr);
    dfs.DFS();
    dfs.result(true);


}
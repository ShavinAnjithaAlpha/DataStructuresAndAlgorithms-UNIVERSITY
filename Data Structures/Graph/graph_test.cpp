#include<iostream>
#include"graph.h"

int main() {

    GraphType<int> gr{10};
     // create a graph with maximum 10 vertices
    char fileName[50];
    std::cout << "file: ";
    std::cin.get(fileName, 50);
    
    gr.load(fileName); // load the intgere map data from the data file to the graph
    std::cout << gr; // display the constructed graph

}
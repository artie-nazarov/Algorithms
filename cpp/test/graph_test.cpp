#include "../graph.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph adjMat({{1,0,0}, {0,1,1}, {1,1,1}}, 3);
    Graph adjList({{2}, {1,3}, {2}}, 3, true);
    Graph adjMatRand(3);
    Graph adjListRand(3, true);

    // Print Graphs
    cout << "Adjecency Matrix graph representation\n" << adjMat << endl << endl;
    cout << "Adjecency List graph representation\n" << adjList << endl << endl;
    cout << "Random Adjecency Matrix graph representation\n" << adjMatRand << endl << endl;
    cout << "Adjecency Matrix graph representation\n" << adjListRand << endl;
    return 0;
}
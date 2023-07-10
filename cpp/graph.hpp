#include <vector>
#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <time.h>
#include <set>

/** Graph class
 * Graph class is an elementary abstraction for a dirtected graph used to quickly prototype graph algorithms
 * 
 * Representation:
 *  All graph vertices are labeled with integers 1 to N
 *  A graph can be represetned both as an Adjecency Matrix and an Adjecency List
*/
class Graph {
    /// Private properties
    private:
        std::vector<std::vector<int>> G;
        /// Generate random number
        /// @param N an upper bound (inclusive)
        inline int gen_rand_num(int N) {return rand() % N + 1;}
    /// Public properties
    public:
        /// Number of Vertices (nodes)
        int N;
        /// Graph constructors
        /// @param N total number of vertices
        /// @param isAdjList false by deault. If true, use Adjecency List graph representation
        /// Construct a random graph
        Graph(int N, bool isAdjList = false) : N(N) {
            srand(time(0));
            // Generate a random Adjecency Matrix/List
            for (int i = 0; i < N; i++) {
                // Adjecency Matrix values
                if (!isAdjList) {
                    std::vector<int> row;
                    for (int j = 0; j < N; j++) {
                        row.push_back(rand() % 2);
                    }
                    G.push_back(row);
                }
                 // Adjecency List values
                else {
                    std::set<int> row;
                    for (int j = 0; j < N; j++) {
                        if (rand() % 2) {
                            row.insert(rand() % N + 1);
                        }
                    }
                    G.push_back(std::vector<int>(row.begin(), row.end()));
                }
            }
        }
        /// Construct a graph from a given input
        /// @param input an input Adjecency Matrix/List in the format: {{1,0,0}, {0,1,1}, {1,1,1}} OR {{2}, {1,3}, {2}}
        Graph(std::initializer_list<std::initializer_list<int>> input, int N, bool isAdjList = false) {
            // Check valid dimensions for Adjecency Matrix
            if (!isAdjList) {
                // if row dimension doesn't match N, throw an error
                if (input.size() != N) {
                    throw std::invalid_argument("Invalid row dimension for input Adjecency Matrix");
                }
                // check column dimension for each row
                for (const auto& row : input)
                {
                    if (row.size() != N) {
                        throw std::invalid_argument("Invalid column dimension for input Adjecency Matrix");
                    }
                }
            }
            std::copy(input.begin(), input.end(), std::back_inserter(G));
        }

        /// Print Graph
        friend std::ostream& operator<<(std::ostream& os, const Graph& G);
};

std::ostream& operator<<(std::ostream& os, const Graph& G)
{
    os << "{\n";
    for (std::vector<int> row : G.G) {
        os << "  {";
        std::vector<int>::iterator iter;
        for (iter = row.begin(); iter < row.end(); iter++) {
            os << *iter;
            if (iter < row.end()-1) {
                os << " ";
            }
        }
        os << "}\n";
    }
    os << "}";
    return os;
}

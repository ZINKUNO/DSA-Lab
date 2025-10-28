#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Graph using Adjacency List 
class GraphAdjList {
private:
    int V;                    // Number of vertices
    vector<list<int>> adj;    // Adjacency list

public:
    GraphAdjList(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add directed edge u -> v
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V)
            adj[u].push_back(v);
    }

    // Compute and return transpose graph using adjacency list
    GraphAdjList getTranspose() {
        GraphAdjList transpose(V);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                transpose.addEdge(v, u);  // Reverse edge: v -> u
            }
        }
        return transpose;
    }

    // Display the graph
    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

// Graph using Adjacency Matrix 
class GraphAdjMatrix {
private:
    int V;                    // Number of vertices
    vector<vector<int>> adj;  // 2D matrix

public:
    GraphAdjMatrix(int vertices) {
        V = vertices;
        adj.assign(V, vector<int>(V, 0));
    }

    // Add directed edge u -> v
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V)
            adj[u][v] = 1;
    }

    // Compute and return transpose graph using adjacency matrix
    GraphAdjMatrix getTranspose() {
        GraphAdjMatrix transpose(V);

        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (adj[u][v] == 1) {
                    transpose.adj[v][u] = 1;  // Reverse edge: v -> u
                }
            }
        }
        return transpose;
    }

    // Display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:\n  ";
        for (int i = 0; i < V; i++) cout << i << " ";
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << i << " ";
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Main Function 
int main() {
    int V = 5;

    cout << "=== Graph using Adjacency List ===" << endl;
    GraphAdjList graphList(V);
    graphList.addEdge(0, 1);
    graphList.addEdge(1, 2);
    graphList.addEdge(2, 3);
    graphList.addEdge(3, 0);
    graphList.addEdge(2, 4);

    cout << "Original Graph:\n";
    graphList.display();

    GraphAdjList transposeList = graphList.getTranspose();
    cout << "Transpose Graph (Adj List):\n";
    transposeList.display();

    cout << "\n=== Graph using Adjacency Matrix ===" << endl;
    GraphAdjMatrix graphMatrix(V);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(1, 2);
    graphMatrix.addEdge(2, 3);
    graphMatrix.addEdge(3, 0);
    graphMatrix.addEdge(2, 4);

    cout << "Original Graph:\n";
    graphMatrix.display();

    GraphAdjMatrix transposeMatrix = graphMatrix.getTranspose();
    cout << "Transpose Graph (Adj Matrix):\n";
    transposeMatrix.display();

    return 0;
}
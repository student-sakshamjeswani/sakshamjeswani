#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
    // Comparison operator to sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) or Union-Find structure
class DSU {
private:
    vector<int> parent, rank;
public:
    // Constructor to initialize DSU
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    // Find function with path compression
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union function with union by rank
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
// Kruskal's Algorithm to find Minimum Spanning Tree
class Kruskal {
private:
    vector<Edge> edges;
    int V; // Number of vertices
public:
    Kruskal(int V) : V(V) {}
    // Add edge to the graph
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }
    // Function to compute the MST
    void findMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        vector<Edge> mst;
        int mstWeight = 0;
        for (const Edge& edge : edges) {
            if (dsu.find(edge.src) != dsu.find(edge.dest)) {
                mst.push_back(edge);
                mstWeight += edge.weight;
                dsu.unite(edge.src, edge.dest);
            }
        }

        // Output the MST
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const Edge& edge : mst) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
        cout << "Total weight of MST: " << mstWeight << endl;
    }
};
int main() {
    int V = 4; // Number of vertices
    Kruskal graph(V);
    // Add edges (src, dest, weight)
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    // Find and print the MST
    graph.findMST();

    return 0;
}

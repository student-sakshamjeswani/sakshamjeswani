#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;  // To represent a pair (weight, vertex)
class Graph {
public:
    int V;  // Number of vertices
    vector<pair<int, int>>* adj;  // Adjacency list
    Graph(int V);
    void addEdge(int u, int v, int weight);
    vector<pair<int, int>> primMST(int startVertex);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}
vector<pair<int, int>> Graph::primMST(int startVertex) {
    vector<int> key(V, INT_MAX);  // To store the minimum weight of an edge connected to the vertex
    vector<int> parent(V, -1);  // To store the parent of each vertex
    vector<bool> inMST(V, false);  // To check if the vertex is included in MST
    key[startVertex] = 0;  // Start with the startVertex with key value 0
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap priority queue
    pq.push({0, startVertex});  // Push the starting vertex with key value 0
    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the minimum key value
        pq.pop();  
        inMST[u] = true;  // Mark the vertex as included in MST
        // Traverse all adjacent vertices of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            // If v is not yet in MST and weight is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;  // Update the parent of v
            }
        }
    }
    // Collect the edges of the MST
    vector<pair<int, int>> mst_edges;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            mst_edges.push_back({parent[i], i});
        }
    }
    return mst_edges;
}
int main() {
    Graph g(5);  // Create a graph with 5 vertices
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    vector<pair<int, int>> mst = g.primMST(0);
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }
    return 0;
}

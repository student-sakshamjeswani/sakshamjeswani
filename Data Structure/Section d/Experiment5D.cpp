#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int, int> pii;  // Pair to represent (distance, vertex)
class Graph {
public:
    int V;  // Number of vertices
    vector<pair<int, int>>* adj;  // Adjacency list for the graph
    Graph(int V);
    void addEdge(int u, int v, int weight);
    vector<int> dijkstra(int startVertex);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}
void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});  // If the graph is undirected
}
vector<int> Graph::dijkstra(int startVertex) {
    vector<int> dist(V, INT_MAX);  // Initialize distances to infinity
    dist[startVertex] = 0;  // Distance to the start vertex is 0
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap to store (distance, vertex)
    pq.push({0, startVertex});  // Push the start vertex with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Extract the vertex with the smallest distance
        pq.pop();
        // Explore neighbors of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step: If a shorter path is found to v
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push the updated distance of v to the priority queue
            }
        }
    }
    return dist;  // Return the distance array
}
int main() {
    Graph g(5);  // Create a graph with 5 vertices
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    int startVertex = 0;
    vector<int> distances = g.dijkstra(startVertex);
    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        if (distances[i] == INT_MAX) {
            cout << "Distance to vertex " << i << " is INF\n";
        } else {
            cout << "Distance to vertex " << i << " is " << distances[i] << endl;
        }  return 0;                                 
}
}

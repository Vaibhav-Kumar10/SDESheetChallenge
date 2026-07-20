// Problem: Dijkstra Algorithm
// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();
            // Skip outdated nodes
            if (curDist > dist[node]) {
                continue;
            }
            for(auto& [nbr, edgeWt] : adj[node]) {
                // int nbr = nbrEdge[0], edgeWt = nbrEdge[1];
                // Better Distanve => update
                if(curDist + edgeWt < dist[nbr]) {
                    dist[nbr] = curDist + edgeWt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }
};

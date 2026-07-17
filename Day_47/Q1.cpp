// Problem: Detect A cycle in Undirected Graph using BFS
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    bool cycleUsingBFS(int src, vector<vector<int>>& adj, 
            vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = true;
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for(auto nbr : adj[node]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});
                }
                else if(nbr != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(cycleUsingBFS(i, adj, visited) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

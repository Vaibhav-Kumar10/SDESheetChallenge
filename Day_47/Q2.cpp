// Problem: Detect A cycle in Undirected Graph using DFS
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    bool cycleUsingDFS(int node, int parent, vector<vector<int>>& adj, 
            vector<bool>& visited) {
        visited[node] = true;
        for(auto nbr : adj[node]) {
            if(!visited[nbr]) {
                if(cycleUsingDFS(nbr, node, adj, visited) == true) {
                    return true;
                }
            }
            else if(nbr != parent) {
                return true;
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
                if(cycleUsingDFS(i, -1, adj, visited) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Problem: Detect A cycle in Undirected Graph using DFS
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, 
            vector<int> &pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto nbr : adj[node]) {
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, pathVisited) == true) {
                    return true;
                }
            }
			// if the node has been previously visited on the same path
            else if(pathVisited[nbr]) {
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(V, 0), pathVisited(V, 0);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

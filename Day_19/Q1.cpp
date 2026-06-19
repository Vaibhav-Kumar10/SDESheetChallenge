// Problem: M-Coloring Problem
// Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
class Solution {
  public:
    bool isPossible(int node, int clr, vector<vector<int>>& adj, 
            vector<int>& color) {
        for(int nbr : adj[node]) {
            if(color[nbr] != -1 && color[nbr] == clr) {
                return false;
            }
        }
        return true;
    }
    bool f(int node, vector<vector<int>>& adj, 
            vector<int>& color, int v, int m) {
        if(node == v) {
            return true;
        }
        for(int clr = 0; clr < m; clr++) {
            if(isPossible(node, clr, adj, color)) {
                color[node] = clr;
                if(f(node + 1, adj, color, v, m)) {
                    return true;
                }
                else {
                    color[node] = -1;
                }
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> color(v, -1);
        return f(0, adj, color, v, m);
    }
};

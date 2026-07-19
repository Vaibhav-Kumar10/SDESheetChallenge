// Problem: Bipartite Check using DFS
// Link: https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    bool isCycleDFS(int node, int curColor, vector<vector<int>>& graph,
                    vector<int>& color, vector<bool>& visited) {
        visited[node] = true;
        color[node] = curColor;
        for (auto nbr : graph[node]) {
            if (!visited[nbr]) {
                if (isCycleDFS(nbr, !curColor, graph, color, visited) == true) {
                    return true;
                }
            } else if (color[nbr] == color[node]) {
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCycleDFS(i, 0, graph, color, visited) == true) {
                    return false;
                }
            }
        }
        return true;
    }
};

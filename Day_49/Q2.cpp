// Problem: Bipartite graph
// Link: https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    for (auto nbr : graph[node]) {
                        if (color[nbr] == -1) {
                            color[nbr] = !color[node];
                            q.push(nbr);
                        } else if (color[nbr] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

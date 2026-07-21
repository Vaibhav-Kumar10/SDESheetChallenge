// Problem: Minimum Spanning Tree
// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        int mst = 0;
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>,
                vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        while(!minHeap.empty()) {
            auto [dist, node] = minHeap.top();
            minHeap.pop();
            if(!visited[node]) {
                mst += dist;
                visited[node] = true;
                for(auto [nbr, wt] : adj[node]) {
                    if(!visited[nbr]) {
                        minHeap.push({wt, nbr});
                    }
                }
            }
        }
        return mst;
    }
};

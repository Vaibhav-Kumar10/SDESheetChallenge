// Problem: Minimum Spanning Tree - Kruskal's Algorithm
// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
class DSU {
    vector<int> parent, size;
  public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = find_parent(parent[u]);
    }
    void union_by_size(int u, int v) {
        int par_u = find_parent(u), par_v = find_parent(v);
        if(par_u == par_v) {
            return;
        }
        if(size[par_u] >= size[par_v]) {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else if(size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
    bool isConnected(int u, int v) {
        return find_parent(u) == find_parent(v);
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DSU dsu(V);
        vector<tuple<int, int, int>> adj;
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj.push_back({wt, u, v});
        }
        sort(adj.begin(), adj.end());

        int mst = 0;

        for(auto edge : adj) {
            auto [wt, u, v] = edge;

            if(!dsu.isConnected(u, v)) {
                dsu.union_by_size(u, v);
                mst += wt;
            }
        }

        return mst;
    }
};

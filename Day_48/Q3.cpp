// Problem: Topological Sort DFS
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, 
            stack<int>& st) {
        visited[node] = true;
        for(auto nbr : adj[node]){
            if(!visited[nbr]) {
                dfs(nbr, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++) { 
            if(!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

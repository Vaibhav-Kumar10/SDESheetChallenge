// Problem: Topological Sort BFS
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<int> ans;
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return ans;
        
    }
};

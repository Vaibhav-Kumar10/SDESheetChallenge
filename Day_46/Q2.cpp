// Problem: DFS of Graph
// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
	void dfsRecursive(int src, vector<vector<int>> & adj,
	        vector<int>& visited, vector<int>& ansDFS) {
		visited[src] = 1;
		ansDFS.push_back(src);
		for (int neighbour : adj[src]) {
			if (!visited[neighbour]) {
				dfsRecursive(neighbour, adj, visited, ansDFS);
			}
		}
	}
	vector<int> dfs(vector<vector<int>> & adj) {
		int v = adj.size(), src = 0;
		vector<int> ansDFS;
		vector<int> visited (v, 0);
		dfsRecursive(src, adj, visited, ansDFS);
		return ansDFS;
	}
};

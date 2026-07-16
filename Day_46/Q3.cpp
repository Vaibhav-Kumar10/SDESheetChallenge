// Problem: BFS of graph
// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// No. of vertices
		int v = adj.size(), src = 0;
		vector<int> ansBFS;
		vector<int> visited(v, 0);
		queue<int> q; ;
		q.push(src);
		visited[src] = 1;
		
		while (!q.empty()) {
			int curNode = q.front();
			q.pop();
			ansBFS.push_back(curNode);
			
			for (int neighbour : adj[curNode]) {
				if (!visited[neighbour]) {
					visited[neighbour] = 1;
					q.push(neighbour);
				}
			}
		}
		return ansBFS;
	}
};

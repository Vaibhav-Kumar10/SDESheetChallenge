// Problem: Rotting Oranges
// Link: https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                    visited[i][j] = 1;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 2;
                }
            }
        }
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                auto [row, col] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i], nc = col + dc[i];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        visited[nr][nc] == 1) {
                        visited[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            // Still some oranges left
            if (q.size() != 0) {
                cnt++;
            }
        }
        return fresh == 0 ? cnt : -1;
    }
};

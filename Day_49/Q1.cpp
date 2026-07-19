// Problem: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<bool>>& visited, int n, int m) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    grid[nr][nc] == '1' && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<bool>>& visited, int n, int m) {
        visited[row][col] = true;
        int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = col + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1' &&
                !visited[nr][nc]) {
                dfs(nr, nc, grid, visited, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    // dfs(i, j, grid, visited, n, m);
                    bfs(i, j, grid, visited, n, m);
                }
            }
        }
        return cnt;
    }
};

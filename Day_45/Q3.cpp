// Problem: Flood Fill
// Link: https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // No chnage requried
        if (image[sr][sc] == color) {
            return image;
        }
        int n = image.size(), m = image[0].size(), startClr = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            // Change color
            image[row][col] = color;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    image[nr][nc] == startClr) {
                    // If nbr has same color as cur node, it should change
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

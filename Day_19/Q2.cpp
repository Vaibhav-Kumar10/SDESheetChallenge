// Problem: Rat in a Maze
// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
  public:
    void f(vector<vector<int>>& maze, int i, int j, int n, 
        vector<vector<bool>>& visited, vector<string>& ans, string path){
        if(i < 0 || i >= n || j < 0 || j >= n 
                 || maze[i][j] == 0 || visited[i][j] == true){
            return;
        }
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        visited[i][j] = true;
        // Down
        f(maze, i + 1, j, n, visited, ans, path + "D");
        // Left
        f(maze, i, j - 1, n, visited, ans, path + "L");
        // Right
        f(maze, i, j + 1, n, visited, ans, path + "R");
        // Up
        f(maze, i - 1, j, n, visited, ans, path + "U");
        visited[i][j] = false;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        vector<string> ans;
        f(maze, 0, 0, n, visited, ans, "");
        return ans;
    }
};

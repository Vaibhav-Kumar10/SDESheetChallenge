// Problem: Super Egg Drop
// Link: https://leetcode.com/problems/super-egg-drop/
class Solution {
  public:
    int eggDrop(int n, int k) {
        vector<vector<int>> floors_covered(k + 1, vector<int>(n + 1, 0));
        int moves = 0, eggs = n;
        while(floors_covered[moves][eggs] < k) {
            moves++;
            for(int egg = 1; egg <= eggs; egg++) {
                // Egg breaks
                int egg_break = floors_covered[moves - 1][egg - 1];
                
                // Egg doesn't break
                int egg_not_break = floors_covered[moves - 1][egg];
                
                floors_covered[moves][egg] = 1 + egg_break + egg_not_break;
            }
        }
        return moves;
    }
    /*
    int f(int eggs, int cur_floor, vector<vector<int>>& dp) {
        if(cur_floor <= 1) {
            return cur_floor;
        }
        if(eggs == 1 || eggs == 0) {
            return cur_floor;
        }
        if(dp[eggs][cur_floor] != -1) {
            return dp[eggs][cur_floor];
        }
        int moves = INT_MAX;
        for(int flr = 1; flr <= cur_floor; flr++) {
            // Egg breaks
            int egg_break = 1 + f(eggs - 1, flr - 1, dp);
            
            // Egg doesn't break
            int egg_not_break = 1 + f(eggs, cur_floor - flr, dp);
            
            int cur_moves = max(egg_break, egg_not_break);
            moves = min(cur_moves, moves);
        }
        return dp[eggs][cur_floor] = moves;
    }
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return f(n, k, dp);
    }
    */
};

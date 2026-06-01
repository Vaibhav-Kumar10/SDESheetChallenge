// Problem: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            vector<int> cur;
            // Start with 1
            long long num = 1;
            cur.push_back(num);
            for (int col = 1; col < row; col++) {
                // Calculate each cell's value
                num = (num * (row - col)) / col;
                cur.push_back(num);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

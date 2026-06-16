// Problem: Subsets II
// Link: https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void f(int ind, int n, vector<int>& arr, vector<int>& cur,
           vector<vector<int>>& ans) {
        ans.push_back(cur);
        for (int i = ind; i < n; i++) {
            // Skip duplicates
            if (i != ind && arr[i] == arr[i - 1]) {
                continue;
            }
            cur.push_back(arr[i]);
            f(i + 1, n, arr, cur, ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        f(0, n, nums, cur, ans);
        return ans;
    }
};

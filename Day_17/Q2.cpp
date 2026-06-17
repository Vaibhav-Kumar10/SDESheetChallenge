// Problem: Combination Sum II
// Link: https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    void f(int ind, int target, vector<int>& arr, vector<int>& cur,
           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || ind == arr.size()) {
            return;
        }
        // Take
        cur.push_back(arr[ind]);
        f(ind + 1, target - arr[ind], arr, cur, ans);
        cur.pop_back();

        // Skip all duplicates
        int next = ind + 1;
        while (next < arr.size() && arr[next] == arr[ind]) {
            next++;
        }
        f(next, target, arr, cur, ans);
    }
    /*
    void f(int ind, int target, vector<int>& arr, vector<int>& cur,
           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || ind == arr.size()) {
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i != ind && arr[i] == arr[i - 1]) {
                continue;
            }
            cur.push_back(arr[i]);
            f(i + 1, target - arr[i], arr, cur, ans);
            cur.pop_back();
        }
    }
    */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        f(0, target, candidates, cur, ans);
        return ans;
    }
};

// Problem: Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            vector<int> current = intervals[i];
            if (prev[1] >= current[0]) {
                prev[1] = max(prev[1], current[1]);
            } else {
                ans.push_back(prev);
                prev = current;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};

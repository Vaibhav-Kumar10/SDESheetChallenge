// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Approach: Use map to store when each number is found. If at any time, we find the target - cur => found.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int curSum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int req = target - nums[i];
            if (mp.find(req) != mp.end()) {
                return {mp[req], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

// Problem: Distinct Numbers in Each Subarray
// Link: https://takeuforward.org/plus/dsa/problems/distinct-numbers-in-each-subarray?source=strivers-sde-sheet
class Solution {
public:
 vector<int> distinctNumbers(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> freq;
    for (int i = 0; i < k; i++) {
        freq[nums[i]]++;
    }
    ans.push_back(freq.size());
    for (int i = k; i < n; i++) {
        freq[nums[i]]++;
        freq[nums[i - k]]--;
        if (freq[nums[i - k]] == 0) {
            freq.erase(nums[i - k]);
        }
        ans.push_back(freq.size());
    }
    return ans;
 }
};

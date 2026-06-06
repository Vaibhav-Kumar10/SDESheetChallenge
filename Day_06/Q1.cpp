// Problem: Majority Element II
// Link: https://leetcode.com/problems/majority-element-ii/
// Approach: Use the Boyer-Moore Majority Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt1 = 0, cnt2 = 0, num1, num2;
        vector<int> ans;
        // Find possible candidates
        for (int num : nums) {
            if (cnt1 == 0 && num != num2) {
                cnt1++;
                num1 = num;
            } else if (cnt2 == 0 && num != num1) {
                cnt2++;
                num2 = num;
            } else if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        // Verify
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == num1) {
                cnt1++;
            }
            if (num == num2) {
                cnt2++;
            }
        }
        if (cnt1 > (n / 3)) {
            ans.push_back(num1);
        }
        if (cnt2 > (n / 3)) {
            ans.push_back(num2);
        }
        return ans;
        /*
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int el : nums) {
            mp[el]++;
            if (mp[el] == ((n / 3) + 1)) {
                ans.push_back(el);
            }
        }
        return ans;
        */
    }
};

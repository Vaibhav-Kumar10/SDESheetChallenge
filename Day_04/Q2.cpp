// Problem: Find Missing and Repeated Values
// Link: https://leetcode.com/problems/find-missing-and-repeated-values/
// Approach: Use map to store the frequencies and then find the repeating and missing number.
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), repeatingNum = -1, missingNum = -1;
        unordered_map<int, int> freq;
        // 1. Store the frequencies of each element of the grid
        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }
        // 2. Check the frequency of each no. to find the missing and the
        // repeating no. from 1 to n*n
        for (int num = 1; num <= n * n; num++) {
            if (freq.find(num) == freq.end()) {
                missingNum = num;
            } else if (freq[num] > 1) {
                repeatingNum = num;
            }
        }
        return {repeatingNum, missingNum};
    }
};

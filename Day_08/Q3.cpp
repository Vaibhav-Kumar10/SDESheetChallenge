// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Use sliding window and map to store the frequency of each character. If at any time, we find the frequency of any char more than 1, 
// shift the window until we get only unique chars in that window. Then update the maximum length.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charOcFreqMap;
        int n = s.size(), l = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {
            // Increase cur char's freq
            charOcFreqMap[s[r]]++;
            // Until we get chars with freq 1 only, shoft the window
            while (charOcFreqMap[s[r]] > 1) {
                charOcFreqMap[s[l]]--;
                l++;
            }
            // Update the maximum length
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

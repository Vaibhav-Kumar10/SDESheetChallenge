// Problem: Longest Subarray with Sum K
// Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// Approach: Use map to store when each prefix sum is found. If at any time, we find the target - cur => found. 
// So calculate that length, and update longest length.
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        // Stores:
        // prefixSum -> first index where this prefix sum appeared
        unordered_map<int, int> prevOccurIdxMap;
        int n = arr.size(), curSum = 0, lngstLen = 0;
        for(int i = 0; i < n; i++) {
            curSum += arr[i];
            // If current prefix sum itself equals k,
            // then subarray [0...i] has sum k.
            if(curSum == k) {
                lngstLen = i + 1;
            }
            // We need:
            // curSum - previousPrefixSum = k
            // Therefore: previousPrefixSum = curSum - k
            int rem = curSum - k;

            // If such a prefix sum was seen before, then the subarray between
            // (previous index + 1) and current index has sum exactly k.
            if(prevOccurIdxMap.find(rem) != prevOccurIdxMap.end()) {
                int len = i - prevOccurIdxMap[rem];
                lngstLen = max(lngstLen, len);
            }

            // Store ONLY the first occurrence of a prefix sum.
            //
            // Why?
            // Suppose the same prefix sum appears multiple times.
            // The earliest occurrence gives the maximum distance
            // from the current index, resulting in the longest
            // possible subarray.
            if(prevOccurIdxMap.find(curSum) == prevOccurIdxMap.end()) {
                prevOccurIdxMap[curSum] = i;
            }
        }
        return lngstLen;
    }
};

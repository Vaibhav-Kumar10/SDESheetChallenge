// Problem: Count Subarrays with given XOR
// Link: Count Subarrays with given XOR
// Approach: Use map to store when each prefix xor is found. If at any time, we find the target ^ cur => found.
// Increase the total count.
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> prevOccurCntMap;
        prevOccurCntMap[0] = 1;
        int n = arr.size(), curSum = 0, lngstCnt = 0;
        for(int i = 0; i < n; i++) {
            curSum ^= arr[i];
            int rem = curSum ^ k;
            if(prevOccurCntMap.find(rem) != prevOccurCntMap.end()) {
                lngstCnt += prevOccurCntMap[rem];
            }
            prevOccurCntMap[curSum]++;
        }
        return lngstCnt;
    }
};

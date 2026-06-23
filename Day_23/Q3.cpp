// Problem: Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Min-heap to keep track of top k frequent elements {frequency,
        // element}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        for (auto [num, freq] : freqMap) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans(k);
        // Extract elements from heap in descending frequency order
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = minHeap.top().second;
            minHeap.pop();
        }

        return ans;
    }
};

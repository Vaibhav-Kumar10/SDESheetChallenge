// Problem: Maximum Sum Combination
// Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        vector<int> ans;
        // Max-heap to store sums with their indices
        priority_queue<tuple<int, int, int>> maxHeap;

        // Set to keep track of visited index pairs
        set<pair<int, int>> visited;
        
        // Push the initial maximum pair (a[0] + b[0])
        maxHeap.push({a[0] + b[0], 0, 0});
        visited.insert({0, 0});

        while(ans.size() < k) {
            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();
            ans.push_back(sum);
            // If (i + 1, j) is valid and not visited, add it to the heap
            if(i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                maxHeap.push({a[i + 1] + b[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            // If (i, j + 1) is valid and not visited, add it to the heap
            if(j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                maxHeap.push({a[i] + b[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};

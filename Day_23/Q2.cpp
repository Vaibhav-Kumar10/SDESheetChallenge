// Problem: Merge k Sorted Arrays
// Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n = mat.size();
        // minHeap to store the smallest elements as
        // {num, arr no, index in that array}
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,  
                       greater<tuple<int, int, int>> > minHeap;
        
        vector<int> ans;
        // First store the first elements from each array
        for(int i = 0; i < n; i++) {
            if (!mat[i].empty()){
                // {num, arr no, index in that array}
                minHeap.push({mat[i][0], i, 0});
            }
        }
        
        // Merge all the arrays
        while(!minHeap.empty()) {
            auto [num, arr_idx, idx] = minHeap.top();
            minHeap.pop();
            ans.push_back(num);
            if(idx + 1 < mat[arr_idx].size()) {
                minHeap.push({mat[arr_idx][idx + 1], arr_idx, idx + 1});
            }
        }
        
        return ans;
    }
};

// Problem: Subset Sums
// Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1
class Solution {
  public:
    void f(int ind, int sum, vector<int>& arr, 
            vector<int>& ans, int n) {
        if(ind == n) {
            ans.push_back(sum);
            return;
        }
        // Pick
        f(ind + 1, sum + arr[ind], arr, ans, n);
        // Not pick
        f(ind + 1, sum, arr, ans, n);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        f(0, 0, arr, ans, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

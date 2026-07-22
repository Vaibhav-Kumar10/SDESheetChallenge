// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > 0) {
                maxProd = max(maxProd * num, num);
                minProd = min(minProd * num, num);
            } else if (num == 0) {
                maxProd = minProd = 0;
            } else {
                int prevMaxProd = maxProd;
                maxProd = max(minProd * num, num);
                minProd = min(prevMaxProd * num, num);
            }
            ans = max(ans, maxProd);
        }
        return ans;
    }
};

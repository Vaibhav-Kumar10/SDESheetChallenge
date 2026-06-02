// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: For every price, if it is the lowest, take it, and calculate the profit using the lowest buying price. Update the max profit evrytime. 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0, minBuyingPrice = prices[0];
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - minBuyingPrice;
            maxProfit = max(maxProfit, profit);
            minBuyingPrice = min(minBuyingPrice, prices[i]);
        }
        return maxProfit;
        /*
        int n = prices.size();
        int maxProfit = INT_MIN;
        int lowestBuyingPrice = INT_MAX;
        for (int price : prices) {
            lowestBuyingPrice = min(lowestBuyingPrice, price);
            maxProfit = max(maxProfit, price - lowestBuyingPrice);
        }
        return maxProfit;
        */
    }
};

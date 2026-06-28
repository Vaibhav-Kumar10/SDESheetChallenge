// Problem: Online Stock Span
// Link: https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    // vector<int> prices;
    stack<pair<int, int>> st;
    int index;
    StockSpanner() { index = 0; }

    int next(int price) {
        int ans;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        if (st.empty()) {
            ans = index - (-1);
        } else {
            ans = index - st.top().second;
        }
        st.push({price, index++});
        return ans;

        // prices.push_back(price);
        // int cnt = 0, n = prices.size();
        // int i = n - 1;
        // while (i >= 0 && prices[i] <= price) {
        //     cnt++;
        //     i--;
        // }
        // return cnt;
        // // for (int i = n - 1; i >= 0; i--) {
        // //     if (prices[i] <= price)
        // //         cnt++;
        // //     else
        // //         break;
        // // }
        // // return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Problem: Largest Rectangle in Histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        long long maxArea = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
            int height = heights[st.top()];
                st.pop();
                int nse = i, pse = (st.empty() ? -1 : st.top());
                maxArea = max(maxArea, height * 1LL * (nse - pse - 1LL));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int nse = n, pse = (st.empty() ? -1 : st.top());
            maxArea = max(maxArea, height * 1LL * (nse - pse - 1LL));
        }
        return maxArea;

        // int n = heights.size();
        // long long maxArea = 0;
        // vector<int> nsei = findNextSmlEl(heights, n);
        // vector<int> psei = findPrevSmlEl(heights, n);
        // for (int i = 0; i < n; i++) {
        //     maxArea =
        //         max(maxArea, heights[i] * 1LL * (nsei[i] - psei[i] - 1LL));
        // }
        // return maxArea;
    }

    // vector<int> findNextSmlEl(vector<int>& arr, int n) {
    //     stack<int> st;
    //     vector<int> nse(n, n);
    //     for (int i = n - 1; i >= 0; i--) {
    //         while (!st.empty() && arr[st.top()] >= arr[i]) {
    //             st.pop();
    //         }
    //         nse[i] = (st.empty() ? n : st.top());
    //         st.push(i);
    //     }
    //     return nse;
    // }
    // vector<int> findPrevSmlEl(vector<int>& arr, int n) {
    //     stack<int> st;
    //     vector<int> pse(n, -1);
    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && arr[st.top()] > arr[i]) {
    //             st.pop();
    //         }
    //         pse[i] = (st.empty() ? -1 : st.top());
    //         st.push(i);
    //     }
    //     return pse;
    // }
};

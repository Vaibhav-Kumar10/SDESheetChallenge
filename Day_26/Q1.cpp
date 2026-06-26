// Problem: Next Smaller Element
// Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, -1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = -1;
            }
            else{
                nse[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nse;
    }
};

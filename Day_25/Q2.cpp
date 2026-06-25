// Problem: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> ngeMap;
        vector<int> nge(n1, -1);
        // Check for every element of nums2 from last
        for (int i = n2 - 1; i >= 0; i--) {
            // Skip all elements that are less than or equal to cur el
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                ngeMap[nums2[i]] = -1;
            } else {
                ngeMap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        // Mark remaining elements
        for (int i = 0; i < n1; i++) {
            nge[i] = ngeMap[nums1[i]];
        }
        return nge;

        /*
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nge(n1, -1);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if(nums1[i] == nums2[j]){
                    for(int k = j+1; k < n2; k++){
                        if(nums2[k] > nums2[j]){
                            nge[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return nge;
        */
    }
};

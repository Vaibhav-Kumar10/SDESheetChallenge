// Problem: Sort a stack
// Link: https://www.geeksforgeeks.org/problems/sort-a-stack/1
class Solution {
  public:
    void insert_sorted_stack(stack<int> &st, int cur) {
        // If stack is empty or top element is smaller, push x
        if (st.empty() || st.top() <= cur) {
            st.push(cur);
            return;
        }
        
        int top = st.top();
        st.pop();

        // Recursively insert x in sorted order
        insert_sorted_stack(st, cur);

        st.push(top);
    }
    void sortStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }

        int cur = st.top();
        st.pop();

        sortStack(st);

        insert_sorted_stack(st, cur);
    }
};

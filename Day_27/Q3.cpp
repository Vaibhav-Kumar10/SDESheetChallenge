// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<long long> st;
    long long minEl;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minEl = val;
        } else {
            if (val < minEl) {
                st.push(2LL * val - minEl); 
                minEl = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        long long topEl = st.top();
        st.pop();
        if (topEl < minEl) {
            minEl = 2 * minEl - topEl;
        }
    }

    int top() {
        if (st.empty()) {
            return -1;
        }
        if (st.top() < minEl) {
            return minEl;
        } else {
            return st.top();
        }
    }

    int getMin() { return minEl; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

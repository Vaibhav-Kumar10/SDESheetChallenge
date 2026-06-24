// Problem: Queue using Stack
// Link: https://www.geeksforgeeks.org/problems/queue-using-stack/1
class myQueue {
    stack<int> st;
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        st.push(x);
    }

    void dequeue() {
        // Implement dequeue operation
        if(st.empty()) {
            return;
        }
        int num = st.top();
        st.pop();

        // If it's the last element => return
        if (st.empty()) {
            return;
        }

        // Recursively pop remaining elements
        dequeue();

        // Push current element back
        st.push(num);
        return;
    }

    int front() {
        // Implement front operation
        if(st.empty()) {
            return -1;
        }
        int num = st.top();
        st.pop();

        // If it's the last element => return
        if (st.empty()) {
            st.push(num);
            return num;
        }

        // Recursively find the front element
        int item = front();  

        // Push current element back
        st.push(num);
        return item;
    }

    int size() {
        // Implement size operation
        return st.size();
    }
};

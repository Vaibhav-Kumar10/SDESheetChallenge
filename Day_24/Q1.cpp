// Problem: Implement stack using array
// Link: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
class myStack {
    vector<int> stack_array;
    int capacity;
  public:
    myStack(int n) {
        // Define Data Structures
        capacity = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return stack_array.size() == 0;
    }

    bool isFull() {
        // check if the stack is full
        return stack_array.size() == capacity;
    }

    void push(int x) {
        // inserts x at the top of the stack
        stack_array.push_back(x);
    }

    void pop() {
        // removes an element from the top of the stack
        if (stack_array.empty()) {
            return;
        }
        int val = stack_array.back();
        stack_array.pop_back();
    }

    int peek() {
        // Returns the top element of the stack
        if (stack_array.empty()) {
            return -1;
        }
        return stack_array.back();
    }
};

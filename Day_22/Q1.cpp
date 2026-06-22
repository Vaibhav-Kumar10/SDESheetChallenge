// Problem: Max Heap implementation
// Link: https://www.geeksforgeeks.org/problems/max-heap-implementation/1
class maxHeap {
  private:
    // Initialize your data members
    vector<int> a;
  public:
    void push(int x) {
        // Insert x into the heap
        a.push_back(x);
        sort(a.begin(), a.end());
    }

    void pop() {
        // Remove the top (maximum) element
        a.pop_back();
    }

    int peek() {
        // Return the top element or -1 if empty
        return a.size() == 0 ? -1 : a.back();
    }

    int size() {
        // Return the number of elements in the heap
        return a.size();
    }
};

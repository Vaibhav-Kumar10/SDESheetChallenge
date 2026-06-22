// Problem: Kth largest element
// Link: https://www.geeksforgeeks.org/problems/kth-largest-element5034/1
class Solution {
  public:
    int KthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, 
                            greater<int>> minHeap;
        for(int a : arr) {
            minHeap.push(a);
            // Store only upto k elements at any time
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

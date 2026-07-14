// Problem: Find Median from Data Stream
// Link: https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // If their sizes differ by more than 1 element
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // minHeap has more elements
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        // If even no. of elements
        if (minHeap.size() == maxHeap.size()) {
            return (double)(minHeap.top() + maxHeap.top()) / 2.0;
        }
        // If even odd. of elements
        return (double)(maxHeap.top() / 1.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

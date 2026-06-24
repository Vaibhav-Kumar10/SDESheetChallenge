// Problem: Queue Using Array
// Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
class myQueue {
    vector<int> queue_array;
    int capacity;
  public:
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return queue_array.size() == 0;
    }

    bool isFull() {
        // check if the queue is full
        return queue_array.size() == capacity;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) {
            return;
        }
        queue_array.push_back(x);
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) {
            return;
        }
        queue_array.erase(queue_array.begin());
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) {
            return -1;
        }
        return queue_array[0];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) {
            return -1;
        }
        return queue_array.back();
    }
};

// Problem: LFU Cache
// Link: https://leetcode.com/problems/lfu-cache/
class LFUCache {
public:
    class Node {
    public:
        int key, value, cnt;
        Node *next, *prev;
        Node(int k, int v) {
            key = k;
            value = v;
            cnt = 1;
        }
    };
    class List {
    public:
        int size;
        Node *head, *tail;
        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void insertNode(Node* node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }
        void deleteNode(Node* node) {
            Node* nextNode = node->next;
            Node* prevNode = node->prev;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--;
        }
    };
    // Hashmap to store the key-nodes pairs
    map<int, Node*> keyNode;
    //  Hashmap to maintain the lists having different frequencies
    map<int, List*> freqListMap;
    int maxSizeCache, minFreq, curSize;
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    // Method to update frequency of data-items
    void updateFreqListMap(Node* node) {
        // Remove from Hashmap
        keyNode.erase(node->key);
        // Update the frequency list hashmap
        freqListMap[node->cnt]->deleteNode(node);
        // If node was the last node having it's frequency
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            // Update the minimum frequency
            minFreq++;
        }

        // Creating a dummy list for next higher frequency
        List* nextHigherFreqList = new List();
        // If the next higher frequency list already exists
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            // Update pointer to already existing list
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        // Increment the count of data-item
        node->cnt += 1;
        // Add the node in front of higher frequency list
        nextHigherFreqList->insertNode(node);
        // Update the
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    // Method to get the value of key from LFU cache
    int get(int key) {
        // Return the value if key exists
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; // Get the node
            int val = node->value;     // Get the value
            updateFreqListMap(node);   // Update the frequency
            // Return the value
            return val;
        }
        // Return -1 if key is not found
        return -1;
    }

    void put(int key, int value) {
        /* If the size of Cache is 0,
        no data-items can be inserted */
        if (maxSizeCache == 0) {
            return;
        }

        // If key already exists
        if (keyNode.find(key) != keyNode.end()) {
            // Get the node
            Node* node = keyNode[key];
            // Update the value
            node->value = value;
            // Update the frequency
            updateFreqListMap(node);
        }
        // Else if the key does not exist
        else {
            // If cache limit is reached
            if (curSize == maxSizeCache) {
                // Remove the least frequently used data-item
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                // Update the frequency map
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                // Decrement the current size of cache
                curSize--;
            }
            // Increment the current cache size
            curSize++;
            // Adding new value to the cache
            minFreq = 1; // Set its frequency to 1
            // Create a dummy list
            List* listFreq = new List();
            // If the list already exist
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                // Update the pointer to already present list
                listFreq = freqListMap[minFreq];
            }
            // Create the node to store data-item
            Node* node = new Node(key, value);
            // Add the node to dummy list
            listFreq->insertNode(node);
            // Add the node to Hashmap
            keyNode[key] = node;
            // Update the frequency list map
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Problem: LRU Cache
// Link: https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *next, *prev;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    };
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> nodeUsageMap;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void insertNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void deleteNode(Node* node) {
        Node *nextNode = node->next, *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    int get(int key) {
        if (nodeUsageMap.find(key) == nodeUsageMap.end()) {
            return -1;
        }
        Node* node = nodeUsageMap[key];
        deleteNode(node);
        insertNode(node);
        nodeUsageMap[key] = head->next;
        return node->val;
    }
    void put(int key, int value) {
        if (nodeUsageMap.find(key) != nodeUsageMap.end()) {
            Node* existingNode = nodeUsageMap[key];
            deleteNode(existingNode);
            nodeUsageMap.erase(key);
        } else if (nodeUsageMap.size() == cap) {
            Node* lastNode = tail->prev;
            deleteNode(lastNode);
            nodeUsageMap.erase(lastNode->key);
        }
        Node* new_node = new Node(key, value);
        insertNode(new_node);
        nodeUsageMap[key] = new_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

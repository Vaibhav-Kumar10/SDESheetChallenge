// Problem: Maximum XOR of Two Numbers in an Array
// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Node {
public:
    Node* links[2];
    bool containsKey(int bit) { return links[bit] != NULL; }
    void setLink(int bit, Node* node) { links[bit] = node; }
    Node* getLink(int bit) { return links[bit]; }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->setLink(bit, new Node());
            }
            node = node->getLink(bit);
        }
    }
    int getMaxXor(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->getLink(!bit);
            } else {
                node = node->getLink(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int maxXor = 0;
        for (int num : nums) {
            trie->insert(num);
        }
        for (int num : nums) {
            maxXor = max(maxXor, trie->getMaxXor(num));
        }
        return maxXor;
    }
};

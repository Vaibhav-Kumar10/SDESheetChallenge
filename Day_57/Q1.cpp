// Problem: Implement Trie (Prefix Tree)
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/
class Node {
public:
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void setLink(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* getLink(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag == true; }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    // O(len(word))
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->setLink(ch, new Node());
            }
            // Move to next reference
            node = node->getLink(ch);
        }
        // Word has ended
        node->setEnd();
    }

    // O(len(word))
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getLink(ch);
        }
        return node->isEnd();
    }

    // O(len(word))
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getLink(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

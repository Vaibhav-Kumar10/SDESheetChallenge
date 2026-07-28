// Problem:  Longest Valid Word with All Prefixes
// Link: https://www.geeksforgeeks.org/problems/longest-valid-word-with-all-prefixes/1
class Node {
  public:
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void setLink(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getLink(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
};
class Trie {
    Node* root;
  public:
    Trie() {
        root = new Node();
    }
    void insert(string& word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->setLink(ch, new Node());
            }
            node = node->getLink(ch);
        }
        node->setEnd();
    }
    bool checkComplete(string& word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                return false;
            }
            node = node->getLink(ch);
            if(node->getEnd() == false) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
  public:    
    string longestValidWord(vector<string>& words) {
        Trie* trie = new Trie();
        for(string word : words) {
            trie->insert(word);
        }
        string completeString = "";
        for(string word : words) {
            if(trie->checkComplete(word)) {
                if(word.size() > completeString.size()) {
                    completeString = word;
                }
                else if(word.size() == completeString.size() 
                        && word < completeString) {
                    completeString = word;
                }
            }
        }
        return completeString;
    }
};

// Problem: Implement Trie 2
// Link: https://www.naukri.com/code360/problems/implement-trie_1387095
#include <bits/stdc++.h> 
class Node {
  public:
    Node* links[26];
    int endsWith = 0, countPrefix = 0;
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void setLink(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getLink(char ch) {
        return links[ch - 'a'];
    }
    void delEnd() {
        endsWith--;
    }
    void setEnd() {
        endsWith++;
    }
    int getEnd() {
        return endsWith;
    }
    int getPrefixCount() {
        return countPrefix;
    }
    void increasePrefixCount() {
        countPrefix++;
    }
    void decreasePrefixCount() {
        countPrefix--;
    }
};
class Trie{
Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->setLink(ch, new Node());
            }
            node = node->getLink(ch);
            node->increasePrefixCount();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->getLink(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->getLink(ch);
        }
        return node->getPrefixCount();
    }

    void erase(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                return;
            }
            node = node->getLink(ch);
            node->decreasePrefixCount();
        }
        node->delEnd();
    }
};

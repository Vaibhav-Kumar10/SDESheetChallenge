// Problem: Count of distinct substrings
// Link: https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1
class Node {
  public:
    Node* links[26];
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void setLink(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getLink(char ch) {
        return links[ch - 'a'];
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size(), cnt = 0;
        Node* root = new Node();
        for(int i = 0; i < n; i++) {
            Node* node = root;
            for(int j = i; j < n; j++) {
                char ch = s[j];
                if(!node->containsKey(ch)) {
                    node->setLink(ch, new Node());
                    cnt++;
                }
                node = node->getLink(ch);
            }
        }
        return cnt;
    }
};

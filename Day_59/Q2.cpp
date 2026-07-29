// Problem: Maximum XOR With an Element From Array
// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* trie = new Trie();
        sort(nums.begin(), nums.end());
        int n = nums.size(), q = queries.size(), ind = 0;
        vector<int> ans(q);
        vector<vector<int>> sorted_queries;
        for (int i = 0; i < q; i++) {
            int x = queries[i][0], a = queries[i][1];
            sorted_queries.push_back({x, a, i});
        }
        sort(sorted_queries.begin(), sorted_queries.end(),
             [&](auto& a, auto& b) { return a[1] < b[1]; });
        for (auto sorted_query : sorted_queries) {
            int x = sorted_query[0], a = sorted_query[1], i = sorted_query[2];
            while (ind < n && nums[ind] <= a) {
                trie->insert(nums[ind]);
                ind++;
            }
            if (ind == 0) {
                ans[i] = -1;
            } else {
                ans[i] = trie->getMaxXor(x);
            }
        }
        return ans;
    }
};

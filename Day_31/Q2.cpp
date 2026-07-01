// Problem: Find the Index of the First Occurrence in a String
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        int i;
        for (i = 0; i < haystack.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

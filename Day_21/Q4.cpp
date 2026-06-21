// Problem: Aggressive Cows
// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
  public:
    bool canPlace(int dist, vector<int>& stalls, int k) {
        int cowCnt = 1, prevPos = stalls[0];
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - prevPos >= dist) {
                cowCnt++;
                prevPos = stalls[i];
                if(cowCnt == k) {
                    return true;
                }
            }
        }
        return (cowCnt >= k);
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int minS = stalls[0], maxS = stalls[stalls.size() - 1];
        int l = 1, r = maxS - minS;

        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            // Try higher distance
            if(canPlace(mid, stalls, k)) {
                l = mid;
            }
            // Try smaller distance
            else {
                r = mid;
            }
        }
        return canPlace(r, stalls, k) ? r : l;
    }
};

// Problem: Minimum Platforms
// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int a = 0, d = 0, n = arr.size();
        int platformCnt = 0, maxPlatformCnt = 0;

        while(a < n && d < n) {
            if(arr[a] <= dep[d]) {
                platformCnt++;
                a ++;
            }
            else {
                platformCnt--;
                d++;
            }
            maxPlatformCnt = max(maxPlatformCnt, platformCnt);
        }

        return maxPlatformCnt;
    }
};

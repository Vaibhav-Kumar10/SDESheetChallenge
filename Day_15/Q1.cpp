// Problem: Activity Selection
// Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
class Activity {
  public:
    int start, end, pos;
};
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<Activity> a(n);
        for(int i = 0; i < n; i++) {
            a[i].start = start[i];
            a[i].end = finish[i];
            a[i].pos = i + 1;
        }
        sort(a.begin(), a.end(), [&](Activity& a1, Activity& a2){
            return a1.end < a2.end;
        });
        vector<int> ans;
        ans.push_back(a[0].pos);
        int freeTime = a[0].end, cnt = 1;
        for(int i = 1; i < n; i++) {
            if(a[i].start > freeTime) {
                freeTime = a[i].end;
                cnt++;
                ans.push_back(a[i].pos);
            }
        }
        return cnt; // ans.size()
    }
};

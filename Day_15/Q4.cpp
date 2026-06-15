// Problem: Fractional Knapsack
// Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Item {
  public:
    double val, wt, val_wt;
};
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> a(n);
        for(int i = 0; i < n; i++) {
            a[i].val = (double)val[i];
            a[i].wt = (double)wt[i];
            a[i].val_wt = (double)val[i] / (double)wt[i];
        }
        sort(a.begin(), a.end(), [&](Item& a1, Item& a2) {
            return a1.val_wt >= a2.val_wt;
        });
        double totalVal = 0.0;
        for(int i = 0; i < n; i++) {
            if(a[i].wt <= capacity) {
                capacity -= a[i].wt;
                totalVal += a[i].val;
            }
            else {
                totalVal += capacity * a[i].val_wt;
                capacity = 0;
                break;
            }
        }
        return totalVal;
    }
};

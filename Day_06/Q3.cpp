// Problem: Reverse Pairs
// Link: https://leetcode.com/problems/reverse-pairs/
// Approach: Use Merge Sort and count the reverse pairs while merging
class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1, cnt = 0;
        for (int i = low; i <= mid; i++) {
            // Count how many reverse pairs are from low to right
            while (right <= high &&
                   (long long)arr[i] > 2 * (long long)arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        // If pointers cross each other, stop
        if (low >= high) {
            return 0;
        }
        int revCnt = 0, mid = low + (high - low) / 2;
        revCnt += mergeSort(arr, low, mid);
        revCnt += mergeSort(arr, mid + 1, high);
        revCnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return revCnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

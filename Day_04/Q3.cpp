// Problem: Count Inversions
// Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Approach: Use Merge Sort and when merging, if the numbers are in incorrect order, calculate the inversions
class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1, cnt = 0;
        while(left <= mid && right <= high){
            // If in reverse order, calculate inversions
            if(arr[left] > arr[right]) {
                cnt += mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if(low >= high){
            return cnt;
        }
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};

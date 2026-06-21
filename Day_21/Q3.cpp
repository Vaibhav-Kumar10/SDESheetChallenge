// Problem: Allocate Minimum Pages
// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
class Solution {
  public:
    int countStudents(vector<int> &arr, int pages) {
        int n = arr.size(), students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            }
            else {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) {
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            if (students > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

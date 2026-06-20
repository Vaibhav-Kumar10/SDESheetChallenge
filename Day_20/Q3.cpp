// Problem: Single Among Doubles in a Sorted
// Link: https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
class Solution {
  public:
    int single(vector<int>& arr) {
        int n = arr.size();
        // Only one element in the array
        if (n == 1) {
            return arr[0];
        }
        // First element is the unique one
        if (arr[0] != arr[1]) {
            return arr[0];
        }
        // Last element is the unique one
        if (arr[n - 1] != arr[n - 2]) {
            return arr[n - 1];
        }

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }
    
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
                (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

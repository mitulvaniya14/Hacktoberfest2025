// Leetcode 852: Peak Index in a Mountain Array
// Issue #8569
// Solved using Binary Search in O(log n) time complexity

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // We are on the left side (uphill), peak is to the right
                low = mid + 1;
            } else {
                // We are on the right side (downhill), or at the peak
                // The peak is at 'mid' or to the left
                high = mid;
            }
        }
        // When low == high, we have found the peak index
        return low;
    }
};

// Main function to test the code
int main() {
    vector<int> arr;
    int n, val;

    cout << "Enter the number of elements in the mountain array (min 3): ";
    cin >> n;

    cout << "Enter the " << n << " elements (must form a mountain, e.g., 1 3 5 4 2): ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr);

    cout << "The peak index is: " << peakIndex << endl;
    cout << "The peak element is: " << arr[peakIndex] << endl;

    return 0;
}

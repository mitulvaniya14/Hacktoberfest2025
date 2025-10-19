// LeetCode 1: Two Sum
// Solution using a hash map (unordered_map)
// Time Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // A map to store: {number, index}
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            int complement = target - currentNum;
            
            // Check if the complement (the other number we need)
            // is already in the map
            if (numMap.count(complement)) {
                // If it is, we found our pair
                return {numMap[complement], i};
            }
            
            // If not, add the current number to the map
            numMap[currentNum] = i;
        }
        
        // Return an empty vector if no solution is found
        return {};
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = sol.twoSum(nums, target);
    
    if (result.size() == 2) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
        cout << "Numbers are: " << nums[result[0]] << " and " << nums[result[1]] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}

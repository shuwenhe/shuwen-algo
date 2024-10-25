#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Map to store number and its index
    vector<int> result; // Vector to store the result indices

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Calculate the complement
        if (num_map.find(complement) != num_map.end()) {
            // If complement exists, return the indices
            result.push_back(num_map[complement]);
            result.push_back(i);
            return result;
        }
        // Store the number and its index in the map
        num_map[nums[i]] = i;
    }
    
    return result; // This return statement is never reached due to the problem guarantee
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    // Output the result
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}

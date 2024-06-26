class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap; // Map to store number and its index
        vector<int> ans;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];

            // Check if complement exists in the map
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                ans.push_back(numIndexMap[complement]); // Index of complement
                ans.push_back(i); // Current index
                break;
            }

            // Store current number and its index in the map
            numIndexMap[nums[i]] = i;
        }

        return ans;
    }
};
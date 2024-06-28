#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <iostream>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Use map to store the elements and their positions
        std::map<int, bool> numMap;
        for (int num : nums) {
            numMap[num] = true;
        }
        
        int longestStreak = 0;

        // Iterate through the map
        for (auto it = numMap.begin(); it != numMap.end(); ++it) {
            // Check if it is the start of a sequence
            if (numMap.find(it->first - 1) == numMap.end()) {
                int currentNum = it->first;
                int currentStreak = 1;

                // Continue the sequence
                while (numMap.find(currentNum + 1) != numMap.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

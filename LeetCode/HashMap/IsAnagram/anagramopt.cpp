#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> count;

        // Increment the count for each character in s
        for (char c : s) {
            count[c]++;
        }

        // Decrement the count for each character in t
        for (char c : t) {
            count[c]--;
        }

        // Check if all counts are zero
        for (auto pair : count) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};

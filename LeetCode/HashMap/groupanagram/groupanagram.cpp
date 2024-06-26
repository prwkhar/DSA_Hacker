class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }

        vector<vector<string>> groupedAnagrams;
        for (auto& pair : anagramMap) {
            groupedAnagrams.push_back(pair.second);
        }

        return groupedAnagrams;
    }
};
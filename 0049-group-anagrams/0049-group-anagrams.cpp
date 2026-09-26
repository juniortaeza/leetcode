class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        for(string str : strs){
            string og = str;
            sort(str.begin(), str.end());
            strMap[str].push_back(og);
        }

        vector<vector<string>> result;
        for(const auto & mappings : strMap)
            result.push_back(mappings.second);

        return result;
    }
};
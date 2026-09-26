class Solution {
public:
    /*
        Time:               O(n*klogk + n), but klogk bounded k <= 100 thus constant = O(n + n) = O(2n) = O(n)
        Auxiliary Space:    O(n), worst-case the strMap can grow to size strs if all strings are unique
        Output Space:       O(n), result will store all strings in strs, just grouped anagramically
    */
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
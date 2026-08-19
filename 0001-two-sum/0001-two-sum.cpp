class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            unordered_map<int, int>::const_iterator key = map.find(complement);
            if(key != map.end())
                return {i, key->second};
            map.insert({nums[i], i});
        }
        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int val=0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            val = target - nums[i];
            if(mp.find(val)!= mp.end()){
                return {mp[val] ,i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};

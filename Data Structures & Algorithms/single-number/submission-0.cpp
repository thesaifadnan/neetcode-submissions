class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0, j=i+1;j<nums.size();i=i+2, j=j+2){
            if(nums[i]^nums[j]){
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};

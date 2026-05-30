class Solution {
public:
    int rob2(vector<int>& nums, int start, int end){
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(end-start+1);
        dp[0] = nums[start];
        dp[1] = max(nums[start+1], dp[0]);
        for(int i=2;i<=end-start;i++){
            dp[i] = max(dp[i-1], dp[i-2]+ nums[i+start]);
        }
        return dp[end-start];
    }

    int rob(vector<int>& nums) {
        return max(rob2(nums, 0,nums.size()-2), rob2(nums, 1, nums.size()-1));
    }
};

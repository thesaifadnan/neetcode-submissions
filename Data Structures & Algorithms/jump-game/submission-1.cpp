class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance =1, len = nums.size();
        if(len ==1){
            return true;
        }else{
            for(int i = len-2;i>=0;i--){
                if(i == 0 && nums[i] >= distance){
                    return true;
                }
                if(nums[i] >= distance){
                    distance = 1;
                }else{
                    distance++;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int i=0, j=nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i] == nums[i-1])continue;

            int l=i+1, j=nums.size()-1;
            while(l<j){
                int sum = nums[i] + nums[j] +nums[l];
                if(sum>0){
                    j--;
                }else if(sum < 0){
                    l++;
                }else{
                    res.push_back({nums[i], nums[l], nums[j]});
                    l++;
                    j--;
                    while(l<j && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

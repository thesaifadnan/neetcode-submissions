class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int maxcount=0;
        for(auto num: mp){
            if(mp.find(num-1)== mp.end()){
                int current = num;
                int count=1;
                while(mp.find(current+1)!=mp.end()){
                    count++;
                    current++;
                }
                maxcount = max(maxcount, count);
            }
        }
        return maxcount;
    }
};

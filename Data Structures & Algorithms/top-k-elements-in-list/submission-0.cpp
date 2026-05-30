class Solution {
public:
    struct Compare{
        bool operator()(pair<int,int>a, pair<int,int>b){
            return a.second> b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>pq;

        for(auto it: mp){
            if(pq.size()<k){
                pq.push({it.first, it.second});
            }else{
                if(pq.top().second < it.second){
                    pq.pop();
                    pq.push({it.first, it.second});
                }
            }
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};

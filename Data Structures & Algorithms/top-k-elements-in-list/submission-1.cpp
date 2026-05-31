class Solution {
public:
    struct Compare{
        bool operator()(pair<int,int>a, pair<int,int>b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto num : nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>pq;

        for(auto it: mp){
            if(pq.size() < k){
                pq.push({it.first, it.second});
            }else{
                if(it.second > pq.top().second){
                    pq.pop();
                    pq.push({it.first, it.second});
                }
            }
        }

        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};



class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>pt;
        for(int i=0;i<position.size();i++){
            pt.push_back({position[i], speed[i]});
        }

        sort(pt.rbegin(), pt.rend());
        stack<double>st;
        st.push(((double)(target-pt[0].first))/pt[0].second);
        for(auto p: pt){
            double time = ((double)(target-p.first))/p.second;
            if(st.top() < time){
                st.push(time);
            }
        }
        return st.size();
    }
};

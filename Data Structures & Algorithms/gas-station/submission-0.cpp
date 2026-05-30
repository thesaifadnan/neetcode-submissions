class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res =0, curGas = 0;
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(),0)){
            return -1;
        }else{
            for(int i=0;i<gas.size();i++){
                curGas += gas[i] - cost[i];
                if(curGas < 0){
                    curGas = 0;
                    res = i+1;
                }
            }
        }
        return res;
    }
};

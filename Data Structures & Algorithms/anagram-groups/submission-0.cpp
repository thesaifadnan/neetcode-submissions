class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(string str:strs){
            vector<int> u_code(26,0);
            for(char c: str){
                u_code[c-'a']++;
            }
            mp[u_code].push_back(str);
        }
        vector<vector<string>> results;
        for(auto item : mp){
            results.push_back(item.second);
        }

        return results;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            vector<int> u_code(26, 0);

            for (char c : str) {
                u_code[c - 'a']++;
            }

            string key = to_string(u_code[0]);
            for (int i = 1; i < 26; i++) {
                key += "," + to_string(u_code[i]);
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> results;
        for (auto& item : mp) {
            results.push_back(item.second);
        }

        return results;
    }
};
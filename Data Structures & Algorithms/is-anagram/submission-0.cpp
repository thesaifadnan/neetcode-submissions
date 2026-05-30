class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() == t.length()){
            vector<int>count(26,0);

            for(char c: s){
                count[c-'a']++;
            }

            for(char c: t){
                count[c-'a']--;
            }

            for(int i: count){
                if(i){
                    return false;
                }
            }
            return true;

        }else{
            return false;
        }
    }
};

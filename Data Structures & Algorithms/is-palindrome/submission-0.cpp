class Solution {
public:
    bool isPalindrome(string s) {
        int j=s.length()-1;
        for(int i=0;i<j; i++){
            while(!isAlphaNum(s[i]) && i<j){
                i++;
            }
            while(!isAlphaNum(s[j]) && j>i){
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            j--;
        }
        return true;
    }

    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};

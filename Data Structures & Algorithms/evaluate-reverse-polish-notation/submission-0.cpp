class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto c:tokens){
            if(c != "+" && c != "-" && c != "*" && c != "/"){
                st.push(stoi(c));
            }
            else{
                int exp1 = st.top(); st.pop();
                int exp2 = st.top(); st.pop();

                if(c == "+"){
                    st.push(exp2 + exp1);
                }
                else if(c == "-"){
                    st.push(exp2 - exp1);
                }
                else if(c == "*"){
                    st.push(exp2 * exp1);
                }
                else{
                    st.push(exp2 / exp1);
                }
            }
        }
        return st.top();
    }
};

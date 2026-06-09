class MinStack {
private:
        std::stack<int>st;
        std::stack<int>minst;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        val = min(val, minst.empty()? val : minst.top());
        minst.push(val);
    }
    
    void pop() {
        minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

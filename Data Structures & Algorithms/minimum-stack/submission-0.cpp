class MinStack {
public:
    stack<int> st;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val = min(val, mini.empty() ? val : mini.top());
        mini.push(val);
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

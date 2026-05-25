using namespace std;

class MinStack {

    
public:

    stack<int> st;
    stack<int> mini;


    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        int curr = min(val, mini.empty() ? val : mini.top());
        mini.push(curr);
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

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            cout << c << endl;
            if (c == '[' or c == '{' or c == '(') st.push(c);
            else {
                if (st.empty()) return false;
                char top = st.top();
                if(c == ']' && top == '[')  st.pop();
                else if(c == ')' && top == '(')  st.pop();
                else if(c == '}' && top == '{')  st.pop();
                else return false;
            }
        }
        return st.empty() == true ? true : false;
    }
};

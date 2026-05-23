class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                cout << "pushing " << s[i] << endl;
            } else {
                if(!st.empty()) {
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == '}' && st.top() != '{') return false;
                    else if(s[i] == ']' && st.top() != '[') return false;
                    else if(s[i] == ')' && st.top() != '(') return false;
                } else {
                    return false;
                }
            }
        }

        if(st.empty() == false) return false;
        return true;
    }
};

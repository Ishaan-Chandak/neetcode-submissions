class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(auto c: tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/") st.push(c);
            else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                int an = stoi(a);
                int bn = stoi(b); 

                int curr;

                if(c == "+") curr = an + bn;
                if(c == "-") curr = bn - an;
                if(c == "*") curr = an * bn; 
                if(c == "/") curr = bn/an; 

                st.push(to_string(curr));
            }
        }

        return stoi(st.top());
    }
};

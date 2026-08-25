class Solution {
  public:
    string compress(string &s) {
        // code here
        stack<char> st;
        int n = s.size();
        int i = n - 1;
        while(n > 0) {
            if(n % 2 == 1) {
                st.push(s[i]);
                s = s.substr(0, n - 1);
                n = s.size();
                i = n - 1;
            } else {
                bool same = true;
                int half = n / 2;
                for(int j=0; j<half; j++) {
                    if(s[j] != s[j + half]) {
                        same = false;
                        break;
                    } 
                }
                
                if(same) {
                    st.push('*');
                    s = s.substr(0, half);
                    n = s.size();
                    i = n - 1;
                } else {
                    st.push(s[i]);
                    s = s.substr(0, n - 1);
                    n = s.size();
                    i = n - 1;
                }
            }
        }
        
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};

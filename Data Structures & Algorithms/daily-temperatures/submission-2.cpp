class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        reverse(temperatures.begin(), temperatures.end());
        stack<int> st;

        int r = 0, n = temperatures.size();
        vector<int> ans(n, 0);

        while(r < n) {
            if(st.empty()) ans[r] = 0;
            else {
                while(!st.empty() && temperatures[st.top()] <= temperatures[r]) st.pop();
                if(st.empty()) ans[r] = 0;
                else {
                    ans[r] = r - st.top();
                }
            }

            st.push(r);
            r++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

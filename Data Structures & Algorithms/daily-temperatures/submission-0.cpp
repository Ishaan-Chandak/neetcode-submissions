class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().second < temperatures[i]) {
                res[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i, temperatures[i]});
        }
        return res;
    }
};

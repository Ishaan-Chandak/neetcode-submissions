class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int ans = 0;
        int n = heights.size();

        for(int i=0; i<n; i++){
            int idx = i;
            if(!st.empty() && st.top().second > heights[i]) {
                while(!st.empty() && st.top().second > heights[i]) {
                    ans = max(ans, (i - st.top().first) * st.top().second);
                    idx = st.top().first;
                    st.pop();
                }
            }

            st.push({idx, heights[i]});
        }

        while(!st.empty()) {
            ans = max(ans, (n - st.top().first) * st.top().second);
            st.pop();
        }

        return ans;
    }
};

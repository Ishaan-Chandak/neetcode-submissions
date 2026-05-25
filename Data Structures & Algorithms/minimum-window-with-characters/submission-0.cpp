class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> mp1, window;

        for(auto i : t) mp1[i]++;

        int cnt=0, req=mp1.size();
        pair<int, int> res = {-1, -1};
        int ans = INT_MAX;
        int l = 0;

        for(int r=0; r<s.size(); r++) {
            char c = s[r];
            window[c]++;

            if(mp1.count(c) && mp1[c] == window[c]){
                cnt++;
            }

            while(cnt == req) {
                if((r - l + 1) < ans) {
                    ans = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(mp1.count(s[l]) && mp1[s[l]] > window[s[l]]){
                    cnt--;
                }

                l++;
            }
        }

        return ans == INT_MAX ? "" : s.substr(res.first, ans);
    }
};

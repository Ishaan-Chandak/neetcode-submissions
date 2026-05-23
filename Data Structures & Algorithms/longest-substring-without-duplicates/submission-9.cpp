class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;

        unordered_map<int, int> mp;
        int n = s.size();
        int l = 0;
        int r = 1;
        int ans = 0;
        mp[s[l] - 'a'] = l;
        mp[s[r] - 'a'] = r;

        if (s[0] == s[1]) { 
            l = r;
            ans =1;
        } else {
            ans =2;
        }

        while(l <= r && r < n){
            r++;
            if (mp.contains(s[r] - 'a')) {
                ans = max(ans, r - l);
                // cout << l << " " << r << " " << ans << endl;
                l = max(mp[s[r] - 'a'] + 1, l);
                mp[s[r] - 'a'] = r;
            } else {
                mp[s[r] - 'a'] = r;
            }
        }
        // cout << r << " " << l << endl;
        if (r == n) ans = max(ans, r - l);

        return ans;
    }
};

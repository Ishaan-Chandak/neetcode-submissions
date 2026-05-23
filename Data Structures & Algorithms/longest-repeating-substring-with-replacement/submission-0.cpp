class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxf = 0;
        int ans = 0;
        int l = 0, r = 0;
        int n = s.size();
        while(r < n) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            while(r - l + 1 - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};

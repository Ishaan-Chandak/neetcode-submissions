class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxf = 0;
        unordered_map<char, int> mp;
        int l=0, r=0, ans=0;
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

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        int ans = INT_MIN;
        int i = 0, j = 0;
        int maxf = INT_MIN;
        while(j < n) {
            mp[s[j]]++;
            maxf = max(maxf, mp[s[j]]);

            while (j - i + 1 - maxf > k) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        // ans = max(ans, j - i + 1);
        return ans;
    }
};

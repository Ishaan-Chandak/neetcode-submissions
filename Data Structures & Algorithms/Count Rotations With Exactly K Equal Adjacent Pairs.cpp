/*

Question is simple but importatn thing to understand is that 
s = s + s

has all the possible strings which can appear when you attach a prefix of s in the back of s
  */


class Solution {
public:
    int score(string s, int i, int j) {
        int cnt = 0;
        for(int k = i; k < j; k++) {
            if(s[k] == s[k + 1]) cnt++;
        }

        return cnt;
    }

    int countRotations(string s, int k) {
        string temp = s;
        int n = s.size();
        s = s + s;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            int temp = score(s, i, i + (n - 1));
            if(temp == k) cnt++;
        }

        return cnt;
    }
};

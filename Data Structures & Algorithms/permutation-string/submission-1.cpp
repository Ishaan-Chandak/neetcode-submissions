class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> mp1, mp2;
        int n1 = s1.size();
        int n2 = s2.size();

        for(int i=0; i<n1; i++) {
            mp1[s1[i] - 'a']++; 
            mp2[s2[i] - 'a']++; 
        }

        if(mp1 == mp2) return true;
        int l = 0;
        for(int i=n1; i<n2; i++) {
            mp2[s2[l]-'a']--;
            mp2[s2[i]-'a']++;

            if(mp2[s2[l]-'a'] == 0) mp2.erase(s2[l]-'a');

            if(mp1 == mp2) return true;

            l++;
        }

        return false;
    }
};

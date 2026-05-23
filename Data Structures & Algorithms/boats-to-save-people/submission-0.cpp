class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        int l = 0;
        int r = n - 1;

        while(l < r) {
            int curr = people[l] + people[r];

            if(curr > limit){
                ans++;
                r--;
            } else {
                ans++;
                l++;
                r--;
            }
        }

        if(l == r) ans++;

        return ans;
    }
};
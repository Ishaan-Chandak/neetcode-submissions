class Solution {
public:
    bool check(int k, int& h, vector<int>& piles) {
        int cnt = 0;
        for(auto pile : piles) {
            if(pile <= k) cnt += 1;
            else if (pile % k == 0) cnt += (pile/k);
            else cnt += ((pile/k) + 1);
        }
        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        for(auto pile : piles) sum += pile;
        long long l = 1, r = sum;
        int ans = -1;

        while(l <= r) {
            long long mid = l + (r - l)/2;
            if(!check(mid, h, piles)) {
                l = mid + 1;
            } else { 
                ans = mid;
                r = mid - 1;
            }
        }

        return ans;
    }
};

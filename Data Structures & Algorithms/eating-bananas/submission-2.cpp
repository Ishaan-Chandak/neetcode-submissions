class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int cnt = 0;
            for(auto i: piles)  {
                // cout << i << " " << mid << " " << ceil((double)i/mid) << endl;
                if(i > mid) cnt += ceil((double)i/mid);
                else cnt += 1;
            }
            // cout << cnt << " " << mid << endl;
            if (cnt > h) l = mid + 1;
            else {
                r = mid - 1;
                ans = min(ans, mid);
            }
        }

        return ans;
    }
};

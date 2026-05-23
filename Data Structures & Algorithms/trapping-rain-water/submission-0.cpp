class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> r(n), l(n);
        r[0] = height[0];

        for(int i=1; i<n; i++){
            if(r[i-1] > height[i]) r[i] = r[i-1];
            else r[i] = height[i];
        }

        l[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            if(l[i+1] > height[i]) l[i] = l[i+1];
            else l[i] = height[i];
        }


        for(auto i : r) cout << i << " ";
        cout << endl;
        for(auto i : l) cout << i << " ";
        cout << endl;

        int ans = 0;
        for(int i = 1; i<n-1; i++){
            if(l[i] == height[i] || r[i] == height[i]) continue;
            else {
                int maxi = min(r[i], l[i]);
                ans += (maxi - height[i]);
            }
        }
        
    return ans;
    }   
};

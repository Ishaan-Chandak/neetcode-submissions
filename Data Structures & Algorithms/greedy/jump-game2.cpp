// classic dp solution uses O(n2)
// this is O(n) solution

// we use two pointers to keep track of the current range of indices that can be reached
// we then find the maximum index that can be reached from the current range
// we then update the left pointer to the right pointer + 1
// we then update the right pointer to the maximum index that can be reached from the current range
// we then increment the steps counter
// we return the steps counter as soon as the max index > (n - 1)

class Solution {
    public:
        int jump(vector<int>& nums) {
            int steps = 0;
            int l = 0, r = 0;
            int n = nums.size();
            while(r < n - 1) {
                int maxi = INT_MIN;
                for(int i = l; i <= r; i++) {
                    maxi = max(i + nums[i], maxi);
                }
                l = r + 1;
                r = maxi;
                steps++;
            }
    
            return steps;
        }
    };
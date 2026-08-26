// 1st greedy solution
// we use a maxi variable to keep track of the maximum index that can be reached
// we then iterate through the array and update the maxi variable if the current index + the value at the current index is greater than the maxi variable
// we then return true if the maxi variable is greater than or equal to the last index
// otherwise we return false
// O(n) time complexity
// O(1) space complexity

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxi = 0;
            int n = nums.size();
            for(int i = 0; i < n; i++) {
                if(maxi >= i) {
                    if(nums[i] + i > maxi) maxi = nums[i] + i;
                    if(maxi >= n - 1) return true;
                } else {
                    return false;
                }
            }
    
            return maxi >= n-1 ? true : false;
        }
    };
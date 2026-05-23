class Solution {
public:
    int quickSelect(int l, int r, vector<int>& nums, int k) {
        int pivot = nums[r];
        int p = l;
        for(int i=l; i<r; i++){
            if(nums[i] <= pivot) {
                int temp = nums[i];
                nums[i] = nums[p];
                nums[p] = temp;
                p++;
            }
        }
        int temp = nums[p];
        nums[p] = pivot;
        nums[r] = temp;

        if(p > k) return quickSelect(l, p-1, nums, k);
        else if (p < k) return quickSelect(p+1, r, nums, k);
        else return nums[p];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n- k;
        return quickSelect(0, n-1, nums, k);
    }
};

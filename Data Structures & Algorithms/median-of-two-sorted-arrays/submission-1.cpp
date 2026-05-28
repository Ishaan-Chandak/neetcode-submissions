class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0, r = A.size();

        while( l <= r) {
            int mid = l + (r - l)/2;
            int other = half - mid;

            int a1 = mid > 0 ? A[mid - 1] : INT_MIN;
            int a2 = mid < A.size() ? A[mid] : INT_MAX;
            int b1 = other > 0 ? B[other - 1] : INT_MIN;
            int b2 = other < B.size() ? B[other] : INT_MAX;

            if(a1 <= b2 && a2 >= b1) {
                if(total % 2 != 0) return max(a1, b1);
                return (max(a1, b1) + min(a2, b2)) / 2.0;
            } else if (a1 > b2) {
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};

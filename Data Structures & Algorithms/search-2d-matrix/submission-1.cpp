class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();

        int l = 0, r = n-1;

        while(l < r) {
            int mid = l + (r - l)/2;
            if(matrix[mid][m-1] == target) return true;

            if(matrix[mid][m-1] >= target && matrix[mid][0] <= target) break;

            if(matrix[mid][m-1] > target) r = mid - 1;
            else l = mid + 1;
        }

        int mid = l + (r - l)/2;

        l = 0;
        r = m - 1;

        while(l <= r) {
            int midC = l + (r - l)/2;
            if(matrix[mid][midC] == target) return true;

            if(matrix[mid][midC] > target) r = midC - 1;
            else l = midC + 1;
        }

        return false;
    }
};

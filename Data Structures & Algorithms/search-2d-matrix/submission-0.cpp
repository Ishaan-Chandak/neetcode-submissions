class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;

        while(top <= bottom) {
            int row = (top + bottom)/2;

            if(target > matrix[row][cols - 1]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bottom = row - 1; 
            } else {
                break;
            }
        }

        if(top > bottom) return false;

        int row = (top + bottom) / 2;

        int l = 0, r = cols - 1;

        while(l <= r) {
            int col = (l + r)/2;

            if(matrix[row][col] < target) {
                l = col + 1;
            } else if (matrix[row][col] > target) {
                r = col - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

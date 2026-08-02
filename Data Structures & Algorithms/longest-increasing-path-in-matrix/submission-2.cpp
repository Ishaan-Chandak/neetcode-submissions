class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    int f(int i, int j, int& n, int& m, vector<vector<int>>& vis, vector<vector<int>>& matrix) {
        if(vis[i][j] != 0) return vis[i][j];
        
        int maxi = 0;
        vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int tempx = i + dx[k];
            int tempy = j + dy[k];
            // cout << tempx << " " << tempy << endl;
            if(tempx >= 0 and tempy >= 0 and tempx < n and tempy < m) {
                if(matrix[tempx][tempy] > matrix[i][j]) {
                    int temp = 1 + f(tempx, tempy, n, m, vis, matrix);
                    maxi = max(temp, maxi);
                }
            }
        }

        return vis[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = INT_MIN;

        int n = matrix.size(), m = matrix[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                int temp = f(i, j, n, m, vis, matrix);
                // cout << temp << endl;
                ans = max(ans, temp);
            }
        }

        return ans + 1;
    }
};

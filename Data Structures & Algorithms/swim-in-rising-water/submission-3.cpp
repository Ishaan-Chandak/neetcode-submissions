using T = tuple<int,int,int>;


class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    bool dfs(int i, int j, int& n, int curr, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(grid[i][j] > curr) return false;
        
        if(i == n-1 && j == n-1) {
            return true;
        }

        vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];

            if(newx >= 0 and newx < n and newy >= 0 and newy < n and vis[newx][newy] == 0) {
                if(dfs(newx, newy, n, curr, vis, grid)) return true;
            }
        }
        vis[i][j] = 0;

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {   
        int n = grid.size();
        // int l = 0, r = n * n;
        // while(l < r) {
        //     int m = l + (r - l)/2;
        //     vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
        //     if(dfs(0, 0, n, m, vis, grid)) {
        //         r = m;
        //     } else {
        //         l = m + 1;
        //     }
        // }
        // return r;

        vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto [wt, i, j] = pq.top();
            pq.pop();
            if(i == n-1 && j == n-1) return wt;
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int k=0; k<4; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];

                if(newx >= 0 and newx < n and newy >= 0 and newy < n and vis[newx][newy] == 0) {
                    int newwt = max(wt, grid[newx][newy]);
                    pq.push({newwt, newx, newy});
                }
            }
        }

        return n*n;
    }
};

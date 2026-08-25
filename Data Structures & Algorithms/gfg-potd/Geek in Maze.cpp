// great question
// here a normal DFS does not work because when we reach r and c in mat, the state depends on the number of u and d we have left
// this should trigger you to think that we need to minimize one of the two things ( u or d )
// then we need to figure out after you optimize u or d how can we find the value of the other variable d or u
// here the logic is (newRow - oldRow = Downward - Upward)
// using the minimized u or d we can find the minimized d and u and finally check if they comply and then we can cnt then if they do and if they dont we skip them

class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        // code here
        
        if(mat[r][c] == '#') return 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {r, c}});
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[r][c] = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int up = it.first;
            int x = it.second.first, y = it.second.second;
            for(int i =0; i<4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx < 0 or newx >= n or newy < 0 or newy >= m) continue;
                
                if(mat[newx][newy] == '#') continue;
                
                int cost = newx == x - 1 ? 1 : 0;
                
                if(cost + dist[x][y] < dist[newx][newy]) {
                    dist[newx][newy] = cost + dist[x][y];
                    pq.push({dist[newx][newy], {newx, newy}});
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dist[i][j] == INT_MAX) continue;
                int down = (i - r) + dist[i][j];
                
                if(down <= d && dist[i][j] <= u) ans++;
            }
        }
        
        return ans;
    }
};

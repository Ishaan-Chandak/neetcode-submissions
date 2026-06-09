class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> visitedP(n, vector<int>(m, 0));
        vector<vector<int>> visitedA(n, vector<int>(m, 0));

        // for(int i=0; i<n; i++) {
        //     if(visitedP[i][0] == 0) bfs(i, 0, heights, visitedP, n, m);
        // }

        // for(int i=0; i<m; i++) {
        //     if(visitedP[0][i] == 0) bfs(0, i, heights, visitedP, n, m);
        // }

        // for(int i=0; i<n; i++) {
        //     if(visitedA[i][m-1] == 0) bfs(i, m-1, heights, visitedA, n, m);
        // }

        // for(int i=0; i<m; i++) {
        //     if(visitedA[n-1][i] == 0) bfs(n-1, i, heights, visitedA, n, m);
        // }

        queue<pair<int, int>> q; 

        for(int i=0; i<n; i++) {
            q.push({i, 0});
        }

        for(int i=0; i<m; i++) {
            q.push({0, i});
        }

        bfs(q, heights, visitedA, n, m);

        for(int i=0; i<n; i++) {
            q.push({i, m-1});
        }

        for(int i=0; i<m; i++) {
            q.push({n-1, i});
        }

        bfs(q, heights, visitedP, n, m);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visitedP[i][j] == 1 and visitedA[i][j] == 1) ans.push_back({i, j});
            }
        }

        return ans;

    }

    // void bfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& visited, int& n, int & m) {
    //     queue<pair<int, int>> q;
    //     q.push({i, j});

    //     while(!q.empty()) {
    //         auto curr = q.front();
    //         q.pop();
    //         visited[curr.first][curr.second] = 1;

    //         for(int k=0; k<4; k++) {
    //             int newX = curr.first + dx[k];    
    //             int newY = curr.second + dy[k];

    //             if(newX >= 0 and newX < n and newY >= 0 and newY < m and visited[newX][newY] == 0 and heights[newX][newY] >= heights[curr.first][curr.second]) {
    //                 q.push({newX, newY});
    //             }    
    //         }
    //     }
    // }

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& heights, vector<vector<int>>& visited, int& n, int & m) {

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            visited[curr.first][curr.second] = 1;

            for(int k=0; k<4; k++) {
                int newX = curr.first + dx[k];    
                int newY = curr.second + dy[k];

                if(newX >= 0 and newX < n and newY >= 0 and newY < m and visited[newX][newY] == 0 and heights[newX][newY] >= heights[curr.first][curr.second]) {
                    q.push({newX, newY});
                }    
            }
        }
    }
};

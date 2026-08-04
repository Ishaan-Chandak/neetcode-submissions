class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n+1);

        for(int i = 0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n + 1, 0);

        pq.push({0, 0});
        int res = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wei = it.first;
            if(vis[node] == 1) continue;

            vis[node] = 1;
            res += wei;

            for(auto k : adj[node]) {
                if(vis[k.first] == 0) pq.push({k.second, k.first}); 
            }
        }

        return res;
    }
};

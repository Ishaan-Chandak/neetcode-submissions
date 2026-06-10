class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, int node) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            if(vis[it] == 0) {
                if(dfs(adj, vis, pathVis, it) == true) return true;
            } else if (pathVis[it] == true) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }   

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        vector<vector<int>> adj(n);

        for(auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
        }

        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                if(dfs(adj, vis, pathVis, i)) return false;
            }
        }

        return true;
    }
};

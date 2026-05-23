class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if(visited[node] == 1) return;

        visited[node] = 1;
        for(auto k: adj[node]) {
            if(visited[k] == 0) dfs(k, adj, visited);
        }
    } 

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};

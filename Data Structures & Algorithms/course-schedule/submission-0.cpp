class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        if(visited[node] == 1) return false;

        if(adj[node].size() == 0) return true;

        visited[node] = 1;
        for(auto k : adj[node]) {
            if(!dfs(k, visited, adj)) return false;
        }

        visited[node] = 0;
        adj[node].clear(); // remove all prerequisites
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        for(auto i : prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i, visited, adj)) return false;
        }

        return true;
    }
};

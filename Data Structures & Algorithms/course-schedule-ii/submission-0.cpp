class Solution {
public:
    bool dfs(int node, vector<int>& output, vector<int>& visited, vector<int>& cycle, vector<vector<int>> adj) {
        if (cycle[node] == 1) return false;

        if (visited[node] == 1) return true;

        cycle[node] = 1;
        for(auto k : adj[node]) {
            if (!dfs(k, output, visited, cycle, adj)) return false;
        }

        cycle[node] = 0;
        visited[node] = 1;
        output.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto pre: prerequisites) adj[pre[0]].push_back(pre[1]);

        vector<int> output;

        vector<int> visited(numCourses, 0);
        vector<int> cycle(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0) {
                if(!dfs(i, output, visited, cycle, adj)) return {};
            }
        }

        return output;
    }
};

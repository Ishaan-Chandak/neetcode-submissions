// Initialize all distances to 0 so every component is considered and negative cycles can be detected even in disconnected graphs.
// If no distance is updated in this pass, further relaxations cannot improve anything, so we can stop early. (TIP)

class Solution {
  public:
    bool isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(n, 0);
        
        for(int j = 0; j < n-1; j++) {
                for(auto &edge: edges) {
                    int u = edge[0];
                    int v = edge[1];
                    int w = edge[2];
                    
                    if(dist[u] != INT_MAX) {
                        if(dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                        }
                    }
                }
            }
            
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                    
                if(dist[u] != INT_MAX) {
                    if(dist[u] + w < dist[v]) {
                        return true;
                    }
                }
            }
        
        return false;
    }
};

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<vector<int>>> adj(V);
        
        for(auto e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            int distCurr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(distCurr > dist[node]) continue;
            
            for(auto it: adj[node]) {
                int edgeDist = it[1];
                int adjNode = it[0];
                
                if(distCurr + edgeDist < dist[adjNode]) {
                    dist[adjNode] = distCurr + edgeDist;
                    pq.push({distCurr + edgeDist, adjNode});
                }
            }
        }
        
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dj = dijkstra(n + 1, times, k);
        int maxi = INT_MIN;

        for(int i = 1; i<=n; i++) maxi = max(dj[i], maxi);

        return maxi == 1e9 ? -1 : maxi;
    }
};

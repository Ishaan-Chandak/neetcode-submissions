class Solution {
public:
    bool dfs(string node, vector<string>& res, unordered_map<string, vector<string>>& adj, int target) {
        if(res.size() == target) return true;

        if(adj.find(node) == adj.end()) return false;

        vector<string> temp = adj[node];
        for(int i = 0; i < temp.size(); i++) {
            string v = temp[i];
            adj[node].erase(adj[node].begin() + i);
            res.push_back(v);
            if(dfs(v, res, adj, target)) return true;
            res.pop_back();
            adj[node].insert(adj[node].begin() + i, v);
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(auto& ticket: tickets) adj[ticket[0]];
        sort(tickets.begin(), tickets.end());
        for(auto& ticket: tickets) adj[ticket[0]].push_back(ticket[1]);

        vector<string> ans = {"JFK"};
        dfs("JFK", ans, adj, tickets.size()+1);
        return ans;
    }
};

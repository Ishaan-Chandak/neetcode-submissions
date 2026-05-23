class Solution {
public:
    int find(int node, vector<int> parent) {
        while(parent[node] != node){
            node = parent[node];
        }
        return node;
    }

    bool unionGraph(int node1, int node2, vector<int>& parent, vector<int>& rank) {
        int parent1 = find(node1, parent);
        int parent2 = find(node2, parent);

        cout << node1 << " " << node2 << " " << parent1 << " " << parent2 << " before" << endl;

        if(parent1 == parent2) return false;

        if(rank[parent1] >= rank[parent2]) {
            rank[parent1] += rank[parent2];
            parent[parent2] = parent1;
        } else {
            rank[parent2] += rank[parent1];
            parent[parent1] = parent2;
        }

        cout << node1 << " " << node2 << " " << parent[parent1] << " " << parent[parent2] << endl;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;

        vector<int> rank(n+1, 1);

        for(auto edge : edges){
            if(unionGraph(edge[0], edge[1], parent, rank) == false) return edge;
        }

        return {};
    }
};

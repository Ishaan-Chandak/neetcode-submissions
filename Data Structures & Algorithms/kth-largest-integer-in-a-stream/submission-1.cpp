class KthLargest {
public:
    priority_queue<int> q;
    int k_g;
    KthLargest(int k, vector<int>& nums) {
        k_g = k;
        for(auto i: nums) q.push(i);
    }
    
    int add(int val) {
        q.push(val);

        vector<int> temp;

        for(int i=0; i<k_g-1; i++) {
            temp.push_back(q.top());
            q.pop();
        }

        int ans = q.top();

        for(auto i : temp) q.push(i);

        return ans;
    }
};

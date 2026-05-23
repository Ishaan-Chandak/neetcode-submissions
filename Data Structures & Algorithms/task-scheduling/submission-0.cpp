class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto task : tasks) mp[task]++;

        priority_queue<int> pq;
        for(auto c : mp){
            pq.push(c.second);
        }

        int time = 0;
        queue<pair<int, int>> q;

        while(!pq.empty() || !q.empty()){

            if(!q.empty()){
                auto curr = q.front();
                int freq = curr.first;
                int nxtTime = curr.second;
                if(nxtTime <= time) {
                    pq.push(freq);
                    q.pop();
                }
            }

            if(!pq.empty()) {
                int curr = pq.top();
                pq.pop();
                curr--;
                if(curr > 0) q.push({curr, time + n + 1}); // time + n + 1 because it will be available "after" n seconds
            }
            time++;
        }

        return time;
    }
};

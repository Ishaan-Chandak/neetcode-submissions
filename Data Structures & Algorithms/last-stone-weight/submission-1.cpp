class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto i : stones) {
            pq.push(i);
        }

        while(pq.size() > 1) {
            int tp1 = pq.top();
            pq.pop();
            int tp2 = pq.top();
            pq.pop();

            if(abs(tp1 - tp2) != 0) pq.push(abs(tp1 - tp2)); 
        }

        if(pq.size() == 1) return pq.top();
        return 0;
    }
};

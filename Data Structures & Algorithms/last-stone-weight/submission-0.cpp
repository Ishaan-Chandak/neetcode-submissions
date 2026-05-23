class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone : stones) pq.push(stone);

        while(pq.size() > 1) {
            if(pq.size() >= 2) {
                int a1 = pq.top();
                pq.pop();
                int a2 = pq.top();
                pq.pop();

                if(a1 > a2) pq.push(a1 - a2);
                else if (a1 < a2) pq.push(a2 - a1);
            }
        }

        if(pq.size() == 0) return 0;
        else return pq.top();
    }
};

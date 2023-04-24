class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i = 0; i < n; i++) pq.push(stones[i]);
        while(pq.size() > 1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top1 == top2) continue;
            if(top1 > top2) pq.push(top1 - top2);
            else pq.push(top2 - top1);
        }
        if(!pq.empty()) return pq.top();
        else return 0;
    }
};
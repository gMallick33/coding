class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> myQueue;
        myQueue.push(start);
        int n = nums.size();
        int ops = 0;
        vector<int> visited(1001, 0);
        while(!myQueue.empty()){
            int size = myQueue.size();
            while(size--){
                int front = myQueue.front();
                myQueue.pop();
                if(front == goal) return ops;
                else{
                    if(front < 0 || front > 1000 || visited[front]) continue;
                    
                    visited[front] = 1;
                    for(auto elem: nums){
                        myQueue.push(front + elem);
                        myQueue.push(front - elem);
                        myQueue.push(front ^ elem);
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};
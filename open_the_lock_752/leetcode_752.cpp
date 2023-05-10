class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, int> visited;
        set<string> mySet(deadends.begin(), deadends.end());
        if(mySet.find("0000") != mySet.end()) return -1;
        queue<string> bfsQueue;
        bfsQueue.push("0000");
        visited["0000"]++;
        int ops = 0;
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            while(size--){
                string up, down;
                string front = bfsQueue.front();
                bfsQueue.pop();
                if(front == target) return ops;

                for(int i = 0; i < 4; i++){
                    up = down = front;
                    
                    char upChar = up[i];
                    char downChar = down[i];
                    up[i] = (upChar == '9' ? '0' : up[i] + 1);
                    down[i] = (downChar == '0' ? '9': down[i] - 1);
                    if(mySet.find(up) == mySet.end() && visited.find(up) == visited.end()){
                        bfsQueue.push(up);
                        visited[up]++;
                    }
                    if(mySet.find(down) == mySet.end() && visited.find(down) == visited.end()){
                        bfsQueue.push(down);
                        visited[down]++;
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};
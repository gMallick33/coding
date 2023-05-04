class LockingTree {
public:
    vector<int> parent, locked;
    vector<vector<int>> child;
    LockingTree(vector<int>& p) {
        int n = p.size();
        child.resize(n);
        parent = p;
        locked.resize(n, -1);
        for(int i = 1; i < n; i++) child[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if(locked[num] != -1) return false;
        else{
            locked[num] = user;
            return true;
        }
    }
    
    bool unlock(int num, int user) {
        if(locked[num] != user) return false;
        else{
            locked[num] = -1;
            return true;
        }
    }
    bool childLocked(int num){
        if(locked[num] != -1) return true;
        for(auto child: child[num]){
            if(childLocked(child)) return true;
        }
        return false;
    }
    bool parentLocked(int num){
        if(num == -1) return false;
        if(locked[num] != -1) return true;
        return parentLocked(parent[num]);
    }
    bool upgrade(int num, int user) {
        if(locked[num] != -1) return false;
        if(childLocked(num) && !parentLocked(parent[num])){
            queue<int> bfsQueue;
            bfsQueue.push(num);
            while(!bfsQueue.empty()){
                int size = bfsQueue.size();
                while(size--){
                    int front = bfsQueue.front();
                    bfsQueue.pop();
                    locked[front] = -1;
                    for(auto child: child[front]){
                        bfsQueue.push(child);
                    }
                }
            }
            locked[num] = user;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
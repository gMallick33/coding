class CustomStack {
public:
    int capacity;
    int currentSize;
    vector<int> myVec;
    CustomStack(int maxSize) {
        capacity = maxSize;
        currentSize = 0;
    }
    
    void push(int x) {
        if(myVec.size() != capacity) {
            myVec.push_back(x);
            currentSize++;
        }
    }
    
    int pop() {
        if(myVec.size() == 0) return -1;
        else{
            int backElem = myVec.back();
            myVec.pop_back();
            currentSize--;
            return backElem;
        }
    }
    
    void increment(int k, int val) {
        int limit = min(k, currentSize);
        for(int i = 0; i < limit; i++){
            myVec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
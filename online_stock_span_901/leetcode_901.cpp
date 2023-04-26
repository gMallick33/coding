class StockSpanner {
public:
    int idx = 0;
    stack<pair<int, int>> myStack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(myStack.empty()){
            myStack.push({price, idx});
            idx++;
            return idx;
        }
        else{
            while(!myStack.empty() && myStack.top().first <= price) myStack.pop();
            if(myStack.empty()){
                myStack.push({price, idx});
                idx++;
                return idx;
            }
            else{
                auto top = myStack.top();
                myStack.push({price, idx});
                idx++;
                return idx - top.second - 1;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
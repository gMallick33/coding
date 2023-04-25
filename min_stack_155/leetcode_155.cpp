class MinStack {
public:
    stack<long long> mystack;
    long long mini;
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(mystack.empty()){
            mystack.push((long long)val);
            mini = (long long)val;
        }
        else{
            if(val < mini){
                mystack.push(2 * (long long)val - mini);
                mini = (long long)val;
            }
            else{
                mystack.push((long long)val);
            }
        }
    }
    
    void pop() {
        if(mystack.empty()) return;
        else{
            long long top = mystack.top();
            mystack.pop();
            if(mystack.empty()){
                mini = LLONG_MAX;
                return;
            }
            else{
                if(top < mini){
                    mini = 2 * mini - top;
                }
            }
        }
    }
    
    int top() {
        if(mystack.empty()) return -1;
        else{
            long long top = mystack.top();
            if(top < mini) return mini;
            else return top;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }
        else q1.push(x);
    }
    
    int pop() {
        if(!q1.empty()){
            while(q1.size() > 1){
                int front = q1.front();
                q1.pop();
                q2.push(front);
            }
            int front = q1.front();
            q1.pop();
            return front;
        }
        else{
            while(q2.size() > 1){
                int front = q2.front();
                q2.pop();
                q1.push(front);
            }
            int front = q2.front();
            q2.pop();
            return front;
        }
    }
    
    int top() {
        if(!q1.empty()){
            while(q1.size() > 1){
                int front = q1.front();
                q1.pop();
                q2.push(front);
            }
            int front = q1.front();
            q1.pop();
            q2.push(front);
            return front;
        }
        else{
            while(q2.size() > 1){
                int front = q2.front();
                q2.pop();
                q1.push(front);
            }
            int front = q2.front();
            q2.pop();
            q1.push(front);
            return front;
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
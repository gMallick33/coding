class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num <= max_heap.top()){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }
        if(max_heap.size() >= min_heap.size() + 2){
            int top = max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        }
        if(min_heap.size() >= max_heap.size() + 2){
            int top = min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size()){
            double max_top = max_heap.top();
            double min_top = min_heap.top();
            return (max_top + min_top) / 2;
        }
        else if(max_heap.size() == min_heap.size() + 1){
            double top = max_heap.top();
            return top;
        }
        else{
            double top = min_heap.top();
            return top;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
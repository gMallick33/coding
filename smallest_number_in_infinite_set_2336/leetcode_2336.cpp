class SmallestInfiniteSet {
public:
    map<int, int> mymap;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            mymap[i]++;
        }
    }
    
    int popSmallest() {
        if(mymap.empty()) return -1;
        else{
            int smallest = mymap.begin()->first;
            mymap.erase(smallest);
            return smallest;
        }
    }
    
    void addBack(int num) {
        if(mymap.find(num) == mymap.end()) mymap[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
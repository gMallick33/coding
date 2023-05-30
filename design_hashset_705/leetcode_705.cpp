class MyHashSet {
public:
    vector<int> myVec;
    MyHashSet() {
        myVec.resize(1000001, 0);
    }
    
    void add(int key) {
        myVec[key] = 1;
    }
    
    void remove(int key) {
        myVec[key] = 0;
    }
    
    bool contains(int key) {
        if(myVec[key]) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
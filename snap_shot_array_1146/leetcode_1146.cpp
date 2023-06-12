class SnapshotArray {
public:
    map<int, map<int, int>> myMap;
    int snapCount = 0;
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++){
            map<int, int> temp;
            temp[0] = 0;
            myMap[i] = temp;
        }
    }
    
    void set(int index, int val) {
        myMap[index][snapCount] = val;
    }
    
    int snap() {
        return snapCount++;
    }
    
    int get(int index, int snap_id) {
        auto it = myMap[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
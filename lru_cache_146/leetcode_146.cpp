class LRUCache {
public:
    list<pair<int, int>> my_list;
    unordered_map<int, list<pair<int, int>>::iterator> my_map;
    int size; 
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(my_map.find(key) == my_map.end()){
            return -1;
        }
        else{
            int elem = my_map[key]->second;
            my_list.splice(my_list.begin(), my_list, my_map[key]);
            return elem;
        }
    }
    
    void put(int key, int value) {
        if(my_map.find(key) != my_map.end()){
            my_list.splice(my_list.begin(), my_list, my_map[key]);
            my_map[key] = my_list.begin();
            my_map[key]->second = value;
            return;
        }
        if(my_list.size() == size){
            int delete_key = my_list.back().first;
            my_map.erase(delete_key);
            my_list.pop_back();
        }
        my_list.push_front({key, value});
        my_map[key] = my_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
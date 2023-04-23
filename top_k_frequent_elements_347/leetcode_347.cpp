class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> my_map;
        int n = nums.size();
        vector<int> answer;
        for(int i = 0; i < n; i++) my_map[nums[i]]++;
        priority_queue<pair<int, int>> max_heap;
        for(auto it = my_map.begin(); it != my_map.end(); it++){
            max_heap.push({it->second, it->first});
            if(max_heap.size() > my_map.size() - k){
                auto top = max_heap.top();
                max_heap.pop();
                answer.push_back(top.second);
            }
        }
        return answer;
    }
};
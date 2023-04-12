class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mymap;
        if(nums.size() == 0) return 0;
        for(int i = 0; i < nums.size(); i++){
            mymap[nums[i]]++;
        }
        int maxi = 1;
        int current = 1;
        for(auto pair: mymap){
            int elem = pair.first;
            if(mymap.find(elem - 1) != mymap.end()) continue;
            else{
                while(mymap.find(elem + 1) != mymap.end()){
                    elem++;
                    current++;
                }
                maxi = max(current, maxi);
                current = 1;
            }
        }
        return maxi;
    }
};
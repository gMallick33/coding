class Solution {
public:
    int halveArray(vector<int>& nums) {
        multiset<long double, greater<long double>> mySet(nums.begin(), nums.end());
        long double half = 0;
        for(int i = 0; i < nums.size(); i++) half += (long double) nums[i] / 2;

        int ops = 0;
        while(!mySet.empty()){
            long double front = *mySet.begin();
            mySet.erase(mySet.begin());
            front = front / 2;
            mySet.insert(front);
            half -= front;
            ops++;
            if(half <= 0) return ops;
        }
        return -1;
    }
};
class Solution {
public:
    int func(int headId, map<int, vector<int>> &subOrds, vector<int> &informTime){
        int maxi = 0;
        if(subOrds.find(headId) == subOrds.end()) return 0;
        for(int i = 0; i < subOrds[headId].size(); i++){
            maxi = max(maxi, informTime[headId] + func(subOrds[headId][i], subOrds, informTime));
        }
        return maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 0 || n == 1) return 0;
        map<int, vector<int>> subOrds;
        for(int i = 0; i < n; i++) subOrds[manager[i]].push_back(i);
        return func(headID, subOrds, informTime);
    }
};
class Solution {
public:
    int func(int idx, vector<int> &cookies, vector<int> &childs){
        if(idx == cookies.size()){
            int ans = 0;
            for(int i = 0; i < childs.size(); i++) ans = max(ans , childs[i]);
            return ans;
        }
        int ans = INT_MAX;
        for(int i = 0; i < childs.size(); i++){
            childs[i] += cookies[idx];
            ans = min(ans, func(idx + 1, cookies, childs));
            childs[i] -= cookies[idx];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> childs(k, 0);
        return func(0, cookies, childs);
    }
};
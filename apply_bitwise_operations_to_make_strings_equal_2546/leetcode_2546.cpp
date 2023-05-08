class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int count1s = 0, count1t = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '1') count1s++;
            if(target[i] == '1') count1t++;
        }
        if(count1s && count1t) return true;
        if(!count1s && !count1t) return true;
        else return false;
    }
};
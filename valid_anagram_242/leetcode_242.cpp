class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        map<char, int> myMap;

        for(int i = 0; i < n; i++) myMap[s[i]]++;
        for(int i = 0; i < n; i++){
            myMap[t[i]]--;
            if(myMap[t[i]] == 0) myMap.erase(t[i]);
        }
        if(myMap.empty()) return true;
        else return false;
    }
        
};
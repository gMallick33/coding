class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            if(temp.size() < goal.size()) return true;
            else return false;
        }
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]) i++;

        while(j >= 0 && s[j] == goal[j]) j--;
        if(i < j) swap(s[i], s[j]);
        if(s == goal) return true;
        else return false;
    }
};
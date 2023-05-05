class Solution {
public:
    int maxVowels(string s, int k) {
        map<char, int> vowelsMap;
        vowelsMap['a']++;
        vowelsMap['e']++;
        vowelsMap['i']++;
        vowelsMap['o']++;
        vowelsMap['u']++;

        int n = s.length();
        int maxi = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vowelsMap.find(s[i]) != vowelsMap.end()) count++;
            if(i >= k){
                if(vowelsMap.find(s[i - k]) != vowelsMap.end()) count--;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
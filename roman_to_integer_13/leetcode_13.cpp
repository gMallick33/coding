class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mymap;
        mymap['I'] = 1;
        mymap['V'] = 5;
        mymap['X'] = 10;
        mymap['L'] = 50;
        mymap['C'] = 100;
        mymap['D'] = 500;
        mymap['M'] = 1000;

        int n = s.size();
        int answer = mymap[s[n - 1]];
        for(int i = n - 2; i >= 0; i--){
            if(mymap[s[i]] < mymap[s[i + 1]]) answer -= mymap[s[i]];
            else answer += mymap[s[i]];
        }
        return answer;
    }
};
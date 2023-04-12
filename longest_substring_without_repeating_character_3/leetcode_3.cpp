class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mymap;
        int left = 0;
        int right = 0;
        int n = s.length();
        int current_length = 0;
        int maxi = 0;
        while(right < n){
            if(mymap.find(s[right]) == mymap.end() || mymap[s[right]] < left){
                current_length++;
                if(current_length > maxi)
                    maxi = current_length;
                mymap[s[right]] = right;
                right++;
            }
            else{
                left = mymap[s[right]] + 1;
                current_length = right - left + 1;
                mymap[s[right]] = right;
                right++;
            }
        }
        return maxi;
    }
};
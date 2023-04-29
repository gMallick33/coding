class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        string zString = needle + "#" + haystack;
        int z = zString.size();
        vector<int> zArray(z);
        zArray[0] = 0;
        int left = 0;
        int right = 0;
        for(int i = 1; i < z; i++){
            if(i > right){
                left = i;
                right = i;
                while(i < z && zString[right] == zString[right - left]) right++;
                zArray[i] = right - left;
                right--;
                if(zArray[i] >= n) return i - n - 1;
            }
            else{
                int pos = i - left;
                if(i + zArray[pos] < right) {
                    zArray[i] = zArray[pos];
                    if(zArray[i] >= n) return i - n - 1;
                }
                else{
                    left = i;
                    while(i < z && zString[right] == zString[right - left]) right++;
                    zArray[i] = right - left;
                    right--;
                    if(zArray[i] >= n) return i - n - 1;
                } 
            }
        }
        return -1;
    }
};
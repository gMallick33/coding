class Solution {
    public:
        int largestVariance(string s) {
            int ans = 0;
            unordered_map<char, int> freq;
            for(auto& c:s){
                freq[c]++;
            }
            for(char ch1='a';ch1<='z';ch1++){
                for(char ch2='a';ch2<='z';ch2++){
                    if(ch1==ch2 || freq[ch1]==0 || freq[ch2]==0)
                    continue;
                    for(int rev=1;rev<=2;rev++){
                        int cnt1 = 0,cnt2 = 0;
                        for(auto& c:s){
                            cnt1 += c==ch1;
                            cnt2 += c==ch2;
                            if(cnt1<cnt2)
                            cnt1 = cnt2 = 0;
                            if(cnt1>0 and cnt2>0)
                            ans = max(ans,cnt1-cnt2);
                        }
                        reverse(s.begin(),s.end());
                    }
                }
            }
            return ans;
        }
};
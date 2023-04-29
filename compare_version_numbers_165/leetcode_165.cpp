class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        for(int i = 0, j = 0; i < n1 || j < n2; i++, j++){
            string s1 = "";
            string s2 = "";

            while(i < n1 && version1[i] != '.'){
                if(s1.size() == 0 && version1[i] == '0') {
                    i++;
                    continue;
                }
                s1 += version1[i];
                i++;
            }

            while(j < n2 && version2[j] != '.'){
                if(s2.size() == 0 && version2[j] == '0') {
                    j++;
                    continue;
                }
                s2 += version2[j];
                j++;
            }

            if(s1.size() > s2.size()) return 1;
            else if(s1.size() < s2.size()) return -1;
            else{
                int ans = s1.compare(s2);
                if(ans > 0) return 1;
                if(ans < 0) return -1;
            }
        }
        return 0;
    }
};
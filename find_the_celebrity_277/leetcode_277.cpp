/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celeb = 0;
        for(int i = 1; i < n; i++){
            if(!knows(celeb, i)) continue;
            else celeb = i;
        }
        for(int i = 0; i < n; i++){
            if(celeb != i){
                if(knows(celeb, i) || !knows(i, celeb)) return -1;
                else continue;
            }
        }
        return celeb;
    }
};
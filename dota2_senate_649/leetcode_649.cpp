class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rQueue, dQueue;
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') rQueue.push(i);
            else dQueue.push(i);
        }
        while(!rQueue.empty() && !dQueue.empty()){
            int rFront = rQueue.front();
            int dFront = dQueue.front();

            rQueue.pop();
            dQueue.pop();

            if(rFront < dFront) rQueue.push(rFront + n);
            else dQueue.push(dFront + n);
        }
        if(!rQueue.empty()) return "Radiant";
        else return "Dire";
    }
};
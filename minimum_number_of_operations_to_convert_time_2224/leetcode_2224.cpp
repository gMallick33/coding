class Solution {
public:
    int convertTime(string current, string correct) {
        int currentHour = stoi(current.substr(0, 2));
        int currentMinute = stoi(current.substr(3, 2));
        int correctHour = stoi(correct.substr(0, 2));
        int correctMinute = stoi(correct.substr(3, 2));

        int ops = 0;
        if(currentMinute <= correctMinute){
            if(currentHour <= correctHour) ops += (correctHour - currentHour);
            else{
                ops += (24 - currentHour + correctHour);
            }
            int minDiff = correctMinute - currentMinute;
            ops += minDiff / 15;
            minDiff = minDiff % 15;

            ops += minDiff / 5;
            minDiff = minDiff % 5;

            ops += minDiff;
            return ops;
        }
        else{
            if(currentHour <= correctHour) ops += (correctHour - currentHour - 1);
            else{
                ops += (24 - currentHour + correctHour - 1);
            }
            int minDiff = 60 - currentMinute + correctMinute;
            ops += minDiff / 15;
            minDiff = minDiff % 15;

            ops += minDiff / 5;
            minDiff = minDiff % 5;

            ops += minDiff;
            return ops;
        }
    }
};
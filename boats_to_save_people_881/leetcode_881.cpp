class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int num_boats = 0;
        int n = people.size();
        int i = 0;
        int j = n - 1;
        sort(people.begin(), people.end());
        while(i <= j){
            num_boats++;
            if(people[i] + people[j] <= limit) i++;
            j--;
        }
        return num_boats;
    }
};
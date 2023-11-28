#define ll long long int
#define mod 1000000007

class Solution {
public:
    int numberOfWays(string corridor) {
        ll n = corridor.size();
        ll lastIndexOfSeat = -1;
        ll answer = 1;
        ll countSeats = 0;
        for(ll i = 0; i < n; i++){
            if(corridor[i] == 'P') continue;
            
            countSeats++;
            if(countSeats >= 3 && countSeats % 2 == 1){
                ll barCounts = i - lastIndexOfSeat;
                answer = (answer * barCounts) % mod;
            }
            lastIndexOfSeat = i;
        }

        return (countSeats == 0 || countSeats % 2 == 1) ? 0 : answer;
    }
};
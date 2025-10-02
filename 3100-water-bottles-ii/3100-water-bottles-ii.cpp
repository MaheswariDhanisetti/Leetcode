class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int ans = 0;

        while(numBottles >= numExchange ){

            numBottles = numBottles - numExchange+1;
            ans += numExchange;
            numExchange++;
        }

        ans += numBottles;

        return ans;

    }
};


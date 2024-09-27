class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        

        /*
        state -> dp[i] the minimum number of coins to make sum i using given coins
        transition -> dp[i] = min( dp[i-coins[j]] , dp[i]) where j from 0 to coins.size() and i-coins[j]>=0
                    INTITUTION
            --------------------------
            --> to make sum i using coins[j] u just needed 1 coins[j] coin + minimum number of coins needed to use to make i-coins[j] sum which is already stored in dp[i-coins[j]]
                so your current dp[i] will be minimum of its current value or dp[i-coins[j]]+1
        base case -> dp[0]=0 as 0 coins needed to make sum 0 
                     initialize all sum initaially in dp vector to INT_MAX
        final answer dp[sum]
        */

        
        vector<int>dp(sum+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=sum;i++){
            
            for(int j=0;j<coins.size();j++){
                
                if(i-coins[j]>=0 && dp[i - coins[j]] != INT_MAX){
                    dp[i]= min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }
        
        if(dp[sum]==INT_MAX) return -1;
        else return dp[sum];
            
    }
};
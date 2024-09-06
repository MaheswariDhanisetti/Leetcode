class Solution {
public:

    vector<int>dp;
    int solve(int n,vector<int>&cost){

        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];
        if(n==0 || n==1) return cost[n];
        

        return dp[n]= min(cost[n]+solve(n-1,cost) , cost[n]+solve(n-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp=vector<int>(cost.size(),-1);

        return min(solve(cost.size()-1,cost) , solve(cost.size()-2,cost));
    }
};
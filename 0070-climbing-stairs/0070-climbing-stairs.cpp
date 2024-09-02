class Solution {
public:
    vector<int>dp;
    int solve(int n){
        
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1)+solve(n-2); 

    }
    int climbStairs(int n) {
       dp=vector<int>(n+1,-1);
       return solve(n);
        
    }
};
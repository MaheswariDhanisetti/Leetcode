class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int m,int n){
        if(i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 and j==n-1) return 1;

        return dp[i][j]= solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m+1, vector<int>(n+1,-1));
        return solve(0,0,m,n);
    }
};
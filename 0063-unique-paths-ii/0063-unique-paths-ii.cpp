class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int m,int n,vector<vector<int>>&grid){
        if(i>=m or j>=n or grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 and j==n-1) return 1;

        return dp[i][j]= solve(i+1,j,m,n,grid)+solve(i,j+1,m,n,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
 
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,obstacleGrid);
    }
};
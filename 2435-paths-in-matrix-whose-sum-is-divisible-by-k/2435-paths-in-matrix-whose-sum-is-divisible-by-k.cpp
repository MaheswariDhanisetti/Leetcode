class Solution {
public:

    const int mod = 1e9+7;

    int solve(vector<vector<int>>&grid ,vector<vector<vector<int>>>&dp , int i ,int j ,int sum , int k)
    {

        //base case
        if(i>=grid.size() or j>=grid[0].size()) return 0;
        
        if(i==grid.size()-1 and j==grid[0].size()-1) return ((sum+grid[i][j])%k==0)?1:0;

        if(dp[i][j][sum]!=-1) return dp[i][j][sum];

        int res = (solve(grid ,dp, i+1 ,j ,(sum+grid[i][j])%k , k) %mod + solve(grid , dp,i ,j+1 , (sum+grid[i][j])%k , k)%mod )%mod;

        return dp[i][j][sum] = res;

    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        vector<vector<vector<int>>>dp(grid.size() , vector<vector<int>>(grid[0].size() , vector<int>(k,-1)));
        
        return solve(grid ,dp, 0 ,0 , 0 , k);

    }
};
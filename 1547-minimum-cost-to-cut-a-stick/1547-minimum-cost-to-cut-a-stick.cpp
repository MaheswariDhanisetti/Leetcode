class Solution {
public:

    int dp[101][101];

    int solve(vector<int>&cuts ,int i , int j ,int st , int en)
    {

        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int res = INT_MAX;

        for(int k = i;k<=j;k++)
        {
            res = min(res , (en-st)+solve(cuts , i,k-1 , st,cuts[k])+solve(cuts , k+1 , j , cuts[k] , en) );
        }

        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin() , cuts.end());

        int si = cuts.size();

        memset(dp , -1,sizeof(dp));

        return solve(cuts ,0 , si-1, 0,n);
    }
};
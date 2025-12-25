class Solution {
public:

    int dp[1001][1001];

    int solve(string &s, string &t, int i , int j )
    {

        if(i>=s.size()) return j>=t.size();

        if(j>=t.size()) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int notpick = solve(s, t, i+1 , j);

        int pick = 0;

        if(s[i]==t[j])
        {
            pick = solve(s, t, i+1 , j+1);
        }

        return dp[i][j] = pick+notpick;
 

    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s , t, 0 ,0 );  
    }
};
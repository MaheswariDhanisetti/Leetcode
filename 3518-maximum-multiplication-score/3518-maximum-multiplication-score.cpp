class Solution {
public:

    long long dp[5][100001];
    long long solve(vector<int>& a, vector<int>& b, int aidx,int bidx){

        //base case
        if(aidx==a.size()) return 0;

        if(bidx>=b.size()) return -922337203685477580;

        if(dp[aidx][bidx]!=-1) return dp[aidx][bidx];

        //not pick
        long long notPicked = solve(a,b,aidx,bidx+1);
         
        //pick
        long long picked= (long long)a[aidx]*b[bidx] + solve(a,b,aidx+1,bidx+1);


        return dp[aidx][bidx] = max(picked,notPicked);

     }
    long long maxScore(vector<int>& a, vector<int>& b) {
        
       memset(dp,-1,sizeof(dp));
       return solve(a,b,0,0);
    }
};
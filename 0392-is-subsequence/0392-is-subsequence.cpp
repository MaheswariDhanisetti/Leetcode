class Solution {
public:
    vector<vector<int>>dp; 
    bool solve(string &s,string &t,int sidx,int tidx){

        if(sidx==s.size()) return true;
        if(t.size()==tidx) return false;
        if(dp[sidx][tidx]!=-1) return dp[sidx][tidx];
        
        if(s[sidx]==t[tidx]){
            return dp[sidx][tidx]= solve(s,t,sidx+1,tidx+1) ; 
        }

        return dp[sidx][tidx]=solve(s,t,sidx,tidx+1);
    }
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        if (s.size() == 0) return true;
        dp=vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
        return solve(s,t,0,0);

    }
};
class Solution {
public:

    void solve(int n, int lf,int rg, string curr,vector<string>&res){

        //base case
        if( (lf+rg)==2*n ) res.push_back(curr); 

        
        if(lf<n){
            solve(n,lf+1,rg,curr+"(",res);
        }
        if(rg<n and rg<lf){
            solve(n,lf,rg+1,curr+")",res);
        }

        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>res;
        solve(n,1,0,"(",res);

        return res;

    }
};
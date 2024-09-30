class Solution {
    
public:
    vector<int>dp;
    int solve(string s, int idx){

        // If the current character is '0', no valid decoding exists for this index
        if (s[idx] == '0') {
            return 0;
        }

        if (idx == s.size()) {
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
        

        

        // Option 1: Take a single digit (valid if not '0')
        int singleDig = solve(s, idx + 1);

        // Option 2: Take two digits if it's valid (between 10 and 26)
        int twoDig = 0;
        if (idx + 1 < s.size() && stoi(s.substr(idx, 2)) <= 26) {
            twoDig = solve(s, idx + 2);
        }

        // Return the total number of ways by combining both options
        return dp[idx]=singleDig + twoDig;
    }
    int numDecodings(string s) {

        /*
        RECURSIVE SOLUTION
        -------------------
        --> base case -> if your curr string becomes "" you can return 1 
        --> subproblems -> at every index you will have two subproblems
                        -> 1. either you can take a single digit if it is greater than 0 
                        -> 2. or you can take 2 digits if it valid and less than 27 
        --> building up main problem from subproblems -> now return the combined total ways of both subprolems

        APPLYING MEMOIZATION
        ---------------------
        -->use  a 2d dp vector to store and keep track of already calculated ways of decoding for a paricular index with partuicular current string.
        --> it will reduce redundant calculations and overlapping subproblems 
        */
        int n=s.size();
        if(n==0) return 0;
        dp=vector<int>(n,-1);
        return solve(s,0);
       
    }
};
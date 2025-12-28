class Solution {
public:

    int solve(vector<int>&cuts ,int i , int j ,int st , int en)
    {

        if(i>j) return 0;

        int res = INT_MAX;

        for(int k = i;k<=j;k++)
        {
            res = min(res , (en-st)+solve(cuts , i,k-1 , st,cuts[k])+solve(cuts , k+1 , j , cuts[k] , en) );
        }

        return res;
    }
    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin() , cuts.end());

        int si = cuts.size();

        return solve(cuts ,0 , si-1, 0,n);
    }
};
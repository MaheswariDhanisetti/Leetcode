class Solution {
public:
    vector<vector<int>>dp;
    bool dfs(int sum,int idx,vector<int>&nums){

        if(sum<0 or idx>=nums.size()) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if(sum==0) return true;

        return dp[idx][sum]=(dfs(sum-nums[idx],idx+1,nums) or dfs(sum,idx+1,nums));
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1 or nums.size()==1 ) return false;

        sum/=2;
        dp=vector<vector<int>>(nums.size(),vector<int>(sum+1,-1));
        return dfs(sum,0,nums);
    }
};
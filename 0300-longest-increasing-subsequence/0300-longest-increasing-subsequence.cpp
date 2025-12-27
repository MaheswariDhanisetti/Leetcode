class Solution {
public:

    int dp[2501][2501];

    int solve(vector<int>&nums , int idx ,int prev)
    {
        if(idx >= nums.size()) return 0;

        if(dp[idx][prev]!=-1) return dp[idx][prev];

        int notpick = solve(nums , idx+1 ,prev);

        int pick = 0;

        if(prev==0 or nums[idx] > nums[prev-1]){
            pick = 1+solve(nums , idx+1 , idx+1);
        }

        return dp[idx][prev] = max(pick , notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp , -1,sizeof(dp));

        return solve(nums , 0 , 0);

    }
};


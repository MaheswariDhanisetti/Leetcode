class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
       /*
       state ->dp[i] the maximum sum of subarray ending at ith index;
       transition -> dp[i] = max(dp[i-1]+nums[i] , nums[i]);
       base case -> dp[0]=nums[0];
       final answer max(dp[0],dp[1]...dp[n]) --> the maximum subarray sum at the end of the array

       */
       int n=nums.size();
       vector<int>dp(n,0);

       dp[0]=nums[0];
       for(int i=1;i<n;i++){
           dp[i]= max(dp[i-1]+nums[i] ,nums[i] );
       }

       return *max_element(dp.begin(),dp.end());
  
    }
};
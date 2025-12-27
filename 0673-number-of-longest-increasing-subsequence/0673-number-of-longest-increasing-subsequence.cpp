class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=dp[0];
        unordered_map<int,int>mp;
        for(int i=1;i<n;i++){

            for(int j=0;j<=i-1;j++){

                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    mp[dp[i]]++;
                }
                
            }
            maxi=max(maxi,dp[i]);
        }

        if(mp[maxi]==0){
            return nums.size();
        }
        return mp[maxi];
    }
};
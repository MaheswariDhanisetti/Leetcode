class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin() , nums.end());

        int n = nums.size();

        vector<pair<int,int>>dp(n); //{previdx , len}

        int maxi = 0 , max_idx = -1 ;
        
        for(int i=0;i<n;i++)
        {
            int curr = 1;
            int idx = i;

            for(int j= i-1;j>=0;j--)
            {
                if(nums[i]%nums[j] ==0 and curr < dp[j].second+1){
                    curr = dp[j].second+1;
                    idx = j;
                }
            }

            dp[i].first = idx;
            dp[i].second = curr;

            if(maxi < dp[i].second)
            {
                maxi = dp[i].second;
                max_idx = i;
            }
        }

        vector<int>res;

        while(max_idx!=dp[max_idx].first)
        {
            res.push_back(nums[max_idx]);
            max_idx = dp[max_idx].first; 
        }

        res.push_back(nums[max_idx]);

        return res;

    }

};



class Solution {
public:
    int countPartitions(vector<int>& nums) {

        long long tot = accumulate(nums.begin() , nums.end() , 0LL);

        long long curr = 0;

        int ans = 0;

        for(int i=0;i<nums.size()-1;i++)
        {

            curr+=nums[i];

            tot -= nums[i];

            if((tot-curr)%2==0)
            {
                ans++;
            }

        }

        return ans;
        
    }
};
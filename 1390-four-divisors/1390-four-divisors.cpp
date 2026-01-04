class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for(int i=0;i<nums.size();i++)
        {
            int sum = 0 , cnt = 0;

            for(int j = 1;j<=sqrt(nums[i]);j++)
            {

                if(nums[i]%j==0)
                {
                    sum += j;
                    cnt++;

                    if(nums[i]/j !=j)
                    {
                        cnt++;
                        sum += nums[i]/j;
                    }
                }

            }

            if(cnt==4) ans+=sum;
        }
        
        return ans;
        
    }
};
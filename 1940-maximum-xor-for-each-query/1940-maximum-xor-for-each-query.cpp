class Solution {
public:

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        // vector<int>ans;
        int val=pow(2,maximumBit)-1;
        int xorsum=0;

        for(int i=0;i<nums.size();i++)
            xorsum=xorsum^nums[i];

        for(int i=nums.size()-1;i>=0;i--)
        {
            // ans.push_back(val^xorsum);
            int temp=nums[i];
            nums[i]=val^xorsum;
            xorsum=xorsum^temp;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};
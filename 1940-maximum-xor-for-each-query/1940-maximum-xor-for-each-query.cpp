class Solution {
public:

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int val=pow(2,maximumBit)-1;
        int xorsum=0;

        for(int i=0;i<nums.size();i++)
            xorsum=xorsum^nums[i];

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(xorsum^val);
            xorsum^=nums[nums.size()-i-1];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1;
        while(i<nums.size() && j<nums.size()){
            while(i<nums.size() && i%2==0 && nums[i]%2==0){
                i+=2;
            }
            while(j<nums.size() && j%2==1 && nums[j]%2==1){
                j+=2;
            }
            if(i>nums.size() || j>nums.size() ) break;
            swap(nums[i],nums[j]);
            i+=2;
            j+=2;
        }
        return nums;
    }
};
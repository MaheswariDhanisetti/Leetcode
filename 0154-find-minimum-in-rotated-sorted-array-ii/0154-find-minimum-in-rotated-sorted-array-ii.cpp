class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int i=0,j=nums.size()-1;
        int n=nums.size();

        while(i<=j){

            int mid= (j+i)/2;
            if(nums[mid]>nums[j])  i=mid+1;
            else if(nums[i]<nums[mid]) j=mid-1;
            else j--;
            
        }

        return nums[i];
    }
};
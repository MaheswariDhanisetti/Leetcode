class Solution {
public:
    bool check(vector<int>& nums) {
        
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                x++;
            }
        }
        
       if(nums[0] < nums[nums.size()-1] ) x++;
       
        return (x==1);
        
    }
};
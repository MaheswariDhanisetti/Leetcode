class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                x=i;
                break;
            }
        }
        
        for(int i=0;i<temp.size();i++){
            if(temp[i] != nums[(i+x)%nums.size()]) return false;
        }
        return true;
        
    }
};
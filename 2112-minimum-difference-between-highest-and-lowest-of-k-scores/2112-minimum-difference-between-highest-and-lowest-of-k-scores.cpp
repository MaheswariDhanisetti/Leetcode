class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            diff=min(diff,abs(nums[i]-nums[k+i-1]));
        }
        return diff;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(n);
        int j=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=nums[j];
                j++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==1){
                ans[i]=nums[j];
                j++;
            }
        }
        return ans;
    }
};
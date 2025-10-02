class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());

        vector<vector<int>>res;

        for(int i =0;i<nums.size();i++){

            if(i!=0 and nums[i] == nums[i-1]) continue;

            int tar = -nums[i];

            int j = i+1 , k = nums.size()-1;

            while(j<k){

                int sum = nums[j] + nums[k];

                if(sum == tar){
                    res.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;

                    while(j<k and nums[j] == nums[j-1]) j++;
                    while(j<k and nums[k] == nums[k+1]) k--;

                }
                else if(sum < tar){
                    j++;
                }
                else{
                    k--;
                }

            }

        }

        return res;

    }
};
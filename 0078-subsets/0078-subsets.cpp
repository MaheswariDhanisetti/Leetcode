class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>subsets;
        int n=nums.size();
        int no_of_sub= (1<<n);
        for(int mask=0;mask<no_of_sub;mask++) //all binary combinations
        {
            vector<int>subset;
            for(int i=0;i<n;i++) //traversing nums to check whether to pick an ele or not based on mask
            {
                if((mask&(1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};
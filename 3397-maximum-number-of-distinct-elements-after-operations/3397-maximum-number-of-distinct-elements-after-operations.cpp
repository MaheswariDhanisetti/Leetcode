class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());

        int mini = (nums[0] - k)+1 ;

        int res = 1;

        for(int i = 1;i<nums.size();i++){

            int low = nums[i] -k;
            int high = nums[i]+k;

            if( max( low , mini) <= high ){
                mini = max(low , mini)+1;
                res++;
            }

        }

        return res;

    }
};


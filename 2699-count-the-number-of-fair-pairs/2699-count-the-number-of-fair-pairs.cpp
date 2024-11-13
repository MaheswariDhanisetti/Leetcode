class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        //we can ignore 
        sort(nums.begin(),nums.end());

        long long pair_cnt=0;

        for(int i=0;i<nums.size();i++){

            //find lower bound where the fair pair for this index starts
            //note:- but to avoid repreated pairs  (2,9) and (9,2) start seraching from next index onwards
            auto lw = lower_bound(nums.begin()+i+1 , nums.end()  , lower-nums[i]);

            //find upper bound where the fair pair for this index ends
            auto up = upper_bound(nums.begin()+i+1 , nums.end()  , upper-nums[i]);

            //now all indexes between the start to end-1 will hold the fair pair condition
            pair_cnt = pair_cnt+(up-lw);

        }
        return pair_cnt;

    }
};
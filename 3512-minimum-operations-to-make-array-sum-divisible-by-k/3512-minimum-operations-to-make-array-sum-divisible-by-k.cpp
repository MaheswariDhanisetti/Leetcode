class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int tot = accumulate(nums.begin() , nums.end(), 0);

        int rem = tot%k;

        return rem;
        
    }
};
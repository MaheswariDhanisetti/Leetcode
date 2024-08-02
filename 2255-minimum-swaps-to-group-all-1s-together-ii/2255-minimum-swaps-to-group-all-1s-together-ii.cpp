class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int window = 0;

        for(auto num: nums){

            if (num == 1) window++;
            
        }

        int n = nums.size();
        int zero = 0;

        for(int i=0;i<window;i++){

            if(nums[i]==0) zero++;
            
        }

        int swap = zero;

        for(int i=window;i<n + window;i++){

            if(nums[i % n] == 0) zero++;

            if(nums[i-window] == 0) zero--;

            swap = min(swap,zero);
            
        }

        return swap;
        
    }
};
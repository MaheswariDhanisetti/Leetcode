class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int curr_or = 0, st = 0;
        int ans = INT_MAX;

        vector<int> bit_cnt(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            curr_or |= nums[i];

            // Count bits in nums[i] that contribute to OR
            for (int j = 0; j < 31; j++) {
                if ((1 << j) & nums[i]) bit_cnt[j]++;
            }

            // Shrink the window from the left if the current OR meets or exceeds k
            while (curr_or >= k && st <= i) {
                ans = min(ans, i - st + 1);  // Update the minimum length
                
                int num = nums[st];
                for (int j = 0; j < 32; j++) {
                    if ((1 << j) & num) {
                        bit_cnt[j]--;
                        if (bit_cnt[j] == 0) {
                            // Unset the bit in OR value
                            int mask = ~(1 << j);
                            curr_or &= mask;
                        }
                    }
                }
                st++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

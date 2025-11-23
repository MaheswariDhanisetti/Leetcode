class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;

        for (int num : nums) {
            vector<int> temp = dp;
            for (int r = 0; r < 3; r++) {
                if (temp[r] != INT_MIN) {
                    int newSum = temp[r] + num;
                    dp[newSum % 3] = max(dp[newSum % 3], newSum);
                }
            }
        }
        return dp[0];
    }
};

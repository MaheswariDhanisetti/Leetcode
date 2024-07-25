class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        auto convert = [&](int a) -> int {
            string str = to_string(a);
            for (int i = 0; i < str.size(); i++) {
                str[i] = mapping[str[i] - '0'] + '0';
            }
            return stoi(str);
        };

        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int temp = convert(nums[i]);
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = temp;
            }
        }

        sort(nums.begin(), nums.end(),
             [&](int a, int b) { return mp[a] < mp[b]; });

        return nums;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        int maxi = 0;
        int ans  =0;

        for(int i:nums){
            mp[i]++;
            maxi = max(maxi ,mp[i]);
        }

        for(auto it:mp){
            if(it.second == maxi){
                ans+=maxi;
            }
        }

        return ans;

    }
};
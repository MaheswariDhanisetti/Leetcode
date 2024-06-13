class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int n=nums.size();
        int pre=0,ans=0;
        
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem=pre%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       if(nums.size()<2) return false;
       unordered_map<int,int>mp;
       mp[0]++;
       int ans=0,pre=0,cnt=0;
       for(int i=0;i<nums.size();i++){
          if(nums[i]%k==0) cnt++;
          pre+=nums[i];
          int rem=pre%k;
          if(mp.find(rem)!=mp.end()){
             ans+=mp[rem];
          }
          mp[rem]++;
       }
       return ans-cnt;
    }
};
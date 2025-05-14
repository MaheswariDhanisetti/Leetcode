class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        int mod = 1e9+7;

        unordered_map<char,int>mp;

        for(char ch : s){
            mp[ch-'a']++;
        }

        for(int i=0;i<t;i++){
            int cnt = mp[25];

            for(int i=24;i>=0;i--){
                mp[i+1] = mp[i];
                mp[i] = 0;
            }

            mp[0] = (mp[0]+cnt)%mod;
            mp[1] = (mp[1]+cnt)%mod;
        }

        long long ans = 0;

        for(auto it:mp){
            ans = (ans + it.second)%mod;
        }

        return ans%mod;

    }
};
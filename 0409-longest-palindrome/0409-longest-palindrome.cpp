class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second%2==1 && cnt==0){
                ans+=it.second;
                cnt++;
            }
            else if(it.second%2==1 && cnt>=1){
                ans+=it.second-1;
            }
            else{
                ans+=it.second;
            }
        }
        return ans;
    }
};
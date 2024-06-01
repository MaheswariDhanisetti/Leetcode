class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            ans+=abs((s[i]-'0')-(s[i+1]-'0'));
        }
        return ans;
    }
};
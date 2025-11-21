class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char,int>mp1 , mp2;

        vector<vector<int>>vis(26 , vector<int>(26,0));

        int ans = 0;

        for(char ch:s){
            mp1[ch]++;
        }

        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];

            mp1[ch]--;

            for(int i=0;i<26;i++)
            {
                char curr = 'a'+i;

                if(mp1[curr]>0 and mp2[curr]>0){
                    if(vis[ch-'a'][i]==0){
                        vis[ch-'a'][i] = 1;
                        ans++;
                        // cout<<curr<<" "<<ch<<" "<<curr<<endl;
                    }
                }
            }

            mp2[ch]++;
        }

        return ans;

    }
};

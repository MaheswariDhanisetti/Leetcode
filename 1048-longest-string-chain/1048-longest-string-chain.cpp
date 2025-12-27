class Solution {
public:
    map<pair<int,string>,int>mp;

    int solve(vector<string>&words , int idx , string prev)
    {

        if(idx>=words.size()) return 0;

        if(mp[{idx, prev}]>0) return mp[{idx ,prev}];

        int notpick = solve(words , idx+1 , prev);

        int pick = 0;

        if(words[idx].size()-prev.size()==1 or prev=="")
        {
            int cnt = 0 , j=0;

            for(int i=0;i<words[idx].size();i++)
            {
                if(j>=prev.size() or words[idx][i]!=prev[j]) cnt++;
                else j++;
            }

            if(cnt==1 or prev=="") pick = 1+solve(words , idx+1 , words[idx]);

        }

        return mp[{idx , prev}] = max(pick , notpick);

    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin() , words.end() , [&](string &a , string &b){
            return a.size() < b.size();
        });

        return solve(words, 0  ,"");
        
    }
};
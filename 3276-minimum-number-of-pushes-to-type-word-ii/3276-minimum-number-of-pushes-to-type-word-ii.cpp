class Solution {
public:
    int minimumPushes(string word) {
        int cnt=0,pos=1;
        int ans=0;
        unordered_map<int,int>mp;
        for(char c:word) mp[c]++;

        vector<pair<int,int>>v;

        for(auto it:mp){
            v.push_back({it.second,it.first});
        }

        sort(v.rbegin(),v.rend());

        for(int i=0;i<v.size();i++){

            if(cnt<=7){
                ans+=v[i].first*pos;
                cnt++;
            }
            else{
                pos++;
                ans+=v[i].first*pos;
                cnt=1;
                
            }
        }

        return ans;
    }
};
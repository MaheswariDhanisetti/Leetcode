class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>ans;
        for(int i:arr1){
            mp[i]++;
        }

        for(int i=0;i<arr2.size();i++){
            if(mp[arr2[i]]>0){
                int val=mp[arr2[i]];
                while(val--){
                    ans.push_back(arr2[i]);
                }
                mp.erase(arr2[i]);
            }
        }

        for(auto it:mp){
            int val=it.second;
            while(val--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int maxi=arrays[0][arrays[0].size()-1];
        int mini=arrays[0][0];
        int res=0;

        for(int i=1;i<arrays.size();i++){

            int si=arrays[i].size();
            
            res=max({res,abs(arrays[i][si-1]-mini),abs(arrays[i][0]-maxi)});
           
            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i][si-1]);

        }

        return res;
    }
};
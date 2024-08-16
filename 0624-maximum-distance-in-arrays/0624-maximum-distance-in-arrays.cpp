class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int fsi=arrays[0].size();
        int n=arrays.size();
        int maxi=arrays[0][fsi-1];
        int mini=arrays[0][0];
        int res=0;

        

        for(int i=1;i<n;i++){

            int si=arrays[i].size();
            
            res=max(res,abs(arrays[i][si-1]-mini));
            res=max(res,abs(arrays[i][0]-maxi));

            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i][si-1]);
            

            
        }

        return res;
    }
};
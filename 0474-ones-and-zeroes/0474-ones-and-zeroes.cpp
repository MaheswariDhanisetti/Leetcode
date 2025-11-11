class Solution {
public:

    int dp[601][101][101];

    int solve(vector<vector<int>>&v ,int idx , int m , int n , int zc ,int oc){

        if(idx >= v.size()) return 0;

        if(dp[idx][zc][oc]!=-1) return dp[idx][zc][oc];

        //pick if zc+v[idx][0] < m and oc < n
        int pick = 0;

        if( zc+v[idx][0] <=m and oc+v[idx][1] <=n ){
            pick = 1+solve(v, idx+1, m ,n ,zc+v[idx][0] , oc+v[idx][1]);
        }

        //not pick
        int not_pick = solve(v , idx+1 , m, n ,zc , oc);

        return dp[idx][zc][oc] = max(pick , not_pick);

    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>>v;

        memset(dp ,-1 , sizeof(dp));

        for(int i=0;i<strs.size();i++){

            int ze = 0 , on =0 ;

            for(int j = 0 ; j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    ze++;
                }
                else{
                    on++;
                }
            }

            v.push_back({ze , on});

        }

        return solve(v ,0 ,  m ,n , 0 , 0);

    }
};
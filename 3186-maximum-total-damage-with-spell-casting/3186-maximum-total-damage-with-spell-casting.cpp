class Solution {
public:

    int find_less_equal(vector<vector<int>>&v , int i , int x){

       for(int j = i-1;j>=0;j--){
            if(v[j][0] <= x) return j;
       }

       return -1;

    }

    long long maximumTotalDamage(vector<int>& power) {
        
        sort(power.begin(),power.end());

        int cnt = 1 , val = power[0];

        vector<vector<int>>v;

        for(int i=1;i<power.size();i++){

            if(val == power[i]){
                cnt++;
            }
            else{
                v.push_back({val , cnt});
                cnt = 1;
                val = power[i];
            }

        }

        v.push_back({val,cnt});

        long long maxi = v[0][0]*v[0][1];

        vector<long long>dp(v.size() , 0);

        dp[0] = maxi;

        for(int i= 1;i<v.size();i++){

            long long lb_idx = find_less_equal(v  , i , v[i][0]-3);

            long long curr =  v[i][0]*v[i][1] ;

            if(lb_idx != -1){
                curr += dp[lb_idx];
            }

            dp[i] = max(dp[i-1] , curr );

            maxi = max(maxi , dp[i]);

            // cout<<dp[i]<<" ";

        }
       
        return maxi;

    }
};
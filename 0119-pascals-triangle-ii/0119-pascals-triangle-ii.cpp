class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        vector<vector<int>>dp;

        dp.push_back({1});
        
        for(int i=1;i<=rowIndex;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){ 
               temp.push_back( dp[i-1][j-1]+dp[i-1][j]);
            }
            temp.push_back(1);
            dp.push_back(temp);
        }

        return dp[rowIndex];

    }
};
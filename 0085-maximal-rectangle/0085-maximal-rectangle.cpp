class Solution {
public:

    int find_max_area(vector<vector<int>>&grid , int row , int m){

        int ans = 0;

        for(int i=0;i<m;i++){

            int lf = i , rg = i;
            while(lf >= 0){
                if(grid[row][lf] >= grid[row][i])lf--;
                else break;
            }

            while(rg < m){
                if(grid[row][rg] >= grid[row][i])rg++;
                else break;
            }
            rg--;
            lf++;
            lf = max( lf , 0);
            rg = min(rg ,m-1 );

            if(grid[row][i]!=0) ans = max(ans , (rg-lf+1) * (grid[row][i]) );

        }
        
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size()  , m = matrix[0].size();

        vector<vector<int>>grid(n , vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(matrix[i][j]=='1') grid[i][j] = 1;

            }
        }

        int res =  find_max_area(grid ,0,m);


        for(int j=1;j<n;j++){

            for(int k = 0;k<m;k++){
                if(grid[j][k]==1){
                    grid[j][k] += grid[j-1][k];
                }
            }

            // cout<<find_max_area(grid ,j,m)<<" ";

            res = max(res , find_max_area(grid ,j,m) );

        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return res;
        
    }
};
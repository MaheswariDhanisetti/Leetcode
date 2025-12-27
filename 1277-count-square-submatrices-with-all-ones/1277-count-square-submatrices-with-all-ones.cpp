class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int ans = 0 , n=matrix.size() , m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    int top = (i>0)?matrix[i-1][j]:0 , left = (j>0)?matrix[i][j-1]:0 , diag = (i>0 and j>0)?matrix[i-1][j-1]:0 ;

                    matrix[i][j] += min({top,left,diag});

                    ans += matrix[i][j];
                }
            }
        }

        return ans;
    }
};




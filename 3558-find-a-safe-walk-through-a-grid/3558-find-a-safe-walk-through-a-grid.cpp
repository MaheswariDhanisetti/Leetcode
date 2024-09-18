class Solution {
public:
   
    vector<vector<vector<int>>> dp; 
    bool res(vector<vector<int>>&grid,int i,int j,int health){

        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 || health<=0){
            return false;
        }


        if(i==grid.size()-1 and j==grid[0].size()-1){
            if(grid[i][j]==1) health--;
            return health>=1;
        }

        if(dp[i][j][health]!=-1) return dp[i][j][health];
        
        int temp=grid[i][j];
        
        grid[i][j]=-1;
        

        bool ans = (res(grid, i - 1, j, health - temp) ||  // Up
                    res(grid, i + 1, j, health - temp) ||  // Down
                    res(grid, i, j - 1, health - temp) ||  // Left
                    res(grid, i, j + 1, health -temp));   // Right

        grid[i][j]=temp;
        return dp[i][j][health]=ans;


    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        dp = vector<vector<vector<int>>>(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(health + 1, -1)));
        return res(grid,0,0,health);
    }
};
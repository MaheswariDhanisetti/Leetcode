class Solution {
    
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int minrow=INT_MAX,maxrow=0,mincol=INT_MAX,maxcol=0;
         
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    minrow=min(minrow,i);
                    maxrow=max(maxrow,i);
                    mincol=min(mincol,j);
                    maxcol=max(maxcol,j);

                }
                
            }
        }

        int width= maxcol-mincol+1;
        int height= maxrow-minrow+1;
        cout<<width*height;
        return width*height;
    }
};
class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size()  , m=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                
                if(grid[i][j]==1){
                    //adding to queue
                    if( i==0 or j==0 or i==grid.size()-1 or j==grid[i].size()-1 ) q.push({i , j}) , grid[i][j] = 0;
                }

            }
        }

        int dirr[] = {0 ,0 ,-1 , 1};
        int dirc[] = {1, -1 , 0 ,0};
        
        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(int k = 0;k<4;k++){

                int r = i+dirr[k];
                int c = j+dirc[k];

                if(r>=0 and c>=0 and r<grid.size() and c<grid[r].size() and grid[r][c] == 1){
                    grid[r][c] = 0;
                    q.push({r, c});
                }

            }

        }

        int cnt = 0;

        for(int i=1;i<n-1;i++){
            for(int j =1;j<m-1;j++){
                if(grid[i][j]==1) cnt++;
            }
        }

        return cnt;

    }
};
class Solution {
public:

    bool isvalid(int nrw ,int ncl , int n){
        if(nrw >=0 and ncl>=0 and nrw < n and ncl <n) return true;

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, pair<int,int>>  , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> >pq; // time , {row ,col}

        pq.push({grid[0][0] , {0,0}});

        int n = grid.size();

        vector<vector<int>>vis(n , vector<int>(n,INT_MAX));

        vector<vector<int>>dir = { {0,1} , {0,-1} , {1,0} , {-1,0} };

        while(!pq.empty()){

            int tm = pq.top().first;
            int rw = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(rw == n-1 and col == n-1) return tm;

            for(int i=0;i<dir.size();i++){
                int nrw = rw+dir[i][0];
                int ncl = col+dir[i][1];

                if(isvalid(nrw , ncl , n) and vis[nrw][ncl] > max(grid[nrw][ncl] , tm) ){

                    vis[nrw][ncl] = max(grid[nrw][ncl] , tm);
                    pq.push({vis[nrw][ncl] , {nrw , ncl}});

                }
            }

        }

        return  0;

    }
};

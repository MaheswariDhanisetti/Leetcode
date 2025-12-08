class Solution {
public:
    void bfs(int i1 , int j1 , vector<vector<char>>board , vector<vector<int>>&vis)
    {
        vis[i1][j1] =1;

        queue<pair<int,int>>q;

        q.push({i1,j1});

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            //right
            if(j+1 < board[i].size() and board[i][j+1]=='X')
            {
                vis[i][j+1] = 1;
                q.push({i ,j+1});
            } 

            //down
            if(i+1 < board.size() and board[i+1][j]=='X')
            {
                vis[i+1][j] =1;
                q.push({i+1 , j});
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        
        int ans = 0;

        vector<vector<int>>vis(board.size() , vector<int>(board[0].size() , 0));

        for(int i=0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j]=='X' and vis[i][j]==0)
                {
                    bfs(i , j, board , vis);
                    ans++;
                }
            }
        }

        return ans;

    }
};
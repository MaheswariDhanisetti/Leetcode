class Solution {
public:
    vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}} ; 
    bool f(vector<vector<char>>&board,int r,int c,int idx,string &word){
        if(idx>=word.size())return true ; 
        if(r>=board.size() || c>=board[r].size() || board[r][c]!=word[idx])return false ; 
        
        char ch = board[r][c]; 
        board[r][c]='.'; 
        for(int i=0;i<4;i++){
            int row = r + dir[i][0] ; 
            int col = c + dir[i][1] ; 
            if(f(board,row,col,idx+1,word))return true ; 
        }
        board[r][c] = ch ; 
        return false ; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(f(board,i,j,0,word))return true ;
            }
        }
        return false ; 
    }
};
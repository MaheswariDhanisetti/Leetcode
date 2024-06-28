class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>>b(3,vector<char>(3,' '));
        char curr='x';
        for(int i=0;i<moves.size();i++){
            b[moves[i][0]][moves[i][1]]=curr;
            (curr=='x')?curr='0':curr='x';
        }

        //checking horizontally
        for(int i=0;i<b.size();i++){
            if(b[i][0]!=' ' && b[i][0]==b[i][1] && b[i][1]==b[i][2]) return (b[i][0]=='x')?"A":"B";
        }

        //checking vertically
        for(int j=0;j<b.size();j++){
            if(b[0][j]!=' ' && b[0][j]==b[1][j] && b[1][j]==b[2][j]) return (b[0][j]=='x')?"A":"B";
        }

        //checking diagonally
        if(b[0][0]!=' '  && b[0][0]==b[1][1] && b[1][1]==b[2][2]) return (b[0][0]=='x')?"A":"B";
        if(b[0][2]!=' ' && b[0][2]==b[1][1] && b[1][1]==b[2][0]) return (b[2][0]=='x')?"A":"B";


        return (moves.size()==9)?"Draw":"Pending";
    }
};
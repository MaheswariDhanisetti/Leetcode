class Solution {
public:

    void changeDirRight(char &currDir){
        if(currDir=='N'){
            currDir='E';
        }
        else if(currDir=='E'){
            currDir='S';
        }
        else if(currDir=='W'){
            currDir='N';
        }
        else{
            currDir='W';
        }
    }

    void changeDirLeft(char &currDir){
        if(currDir=='N'){
            currDir='W';
        }
        else if(currDir=='E'){
            currDir='N';
        }
        else if(currDir=='W'){
            currDir='S';
        }
        else{
            currDir='E';
        }
    }

    void makeMove(char &currDir,int &x,int &y,int dist,set<pair<int,int>>&st){

        
        for(int i=1;i<=dist;i++){

            if(currDir=='E'){
                if(st.find({x+1,y})==st.end()){
                    x++;
                }
                else break;
            }
            else if(currDir=='W'){
                if(st.find({x-1,y})==st.end()){
                    x--;
                }
                else break;
            }
            else if(currDir=='N'){
                if(st.find({x,y+1})==st.end()){
                    y++;
                }
                else break;
            }
            else if(currDir=='S'){
                if(st.find({x,y-1})==st.end()){
                    y--;
                }
                else break;
            }
        }

    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        

        set<pair<int,int>>st;

        for(int i=0;i<obstacles.size();i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }

        long long ans=0;
        int x=0,y=0;
        // if(st.find({0,0})!=st.end()){
        //     x=0;
        //     y-=1;
        // }
        char currDir='N';
        for(int i=0;i<commands.size();i++){

            if(commands[i]==-1){
               changeDirRight(currDir);
            }
            else if(commands[i]==-2){
                changeDirLeft(currDir);
            }
            else{

                makeMove(currDir,x,y,commands[i],st);
                long long curr= (x*x)+(y*y);
                ans=max(ans, curr );

            }
        }

        return ans;


    }
};
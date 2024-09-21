class Solution {
public:

    void solve(int i,int n,vector<int>&res){

        if(i>n) return;

        res.push_back(i);
        for(int j=0;j<=9;j++){
            solve((i*10)+j,n,res);
        }
    }

    vector<int> lexicalOrder(int n) {
       vector<int>res; 

       for(int i=1;i<=9;i++){
        solve(i,n,res);
       }
       return res;
        
    }
};
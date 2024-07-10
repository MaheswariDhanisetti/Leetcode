class Solution {
public:
    int minOperations(vector<string>& logs) {
        int op=0;

        for(int i=0;i<logs.size();i++){
            string s=logs[i];
            if(s=="../"){
                if(op>0) op--;
            }
            else if(s=="./"){
                op=op;
            }
            else{
                op++;
            }
        }
        return op;
    }
};
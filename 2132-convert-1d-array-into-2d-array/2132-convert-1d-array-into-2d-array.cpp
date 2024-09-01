class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>>res;
        if(m*n !=original.size()) return res;
        vector<int>temp;
        for(int i=0;i<original.size();i++){
            temp.push_back(original[i]);
            if((i+1)%n==0){
               res.push_back(temp);
               temp.clear(); 
            }
            
        }
        return res;


    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(int i=0;i<details.size();i++){
            int age=details[i][11]-'0';
            age=age*10+(details[i][12]-'0');
            if(age>60) res++;
        }
        return res;
    }
};
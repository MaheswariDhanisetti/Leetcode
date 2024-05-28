class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool low=0,up=0,dig=0,sp=0;
        for(int i=0;i<password.size();i++){
            if(password[i]>='a' && password[i]<='z') low=1;
            if(password[i]>='A' && password[i]<='Z') up=1;
            if(password[i]-'0'>=0 && password[i]-'0'<=9) dig=1;
            if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+') sp=1;
            if(i<password.size()-1 && password[i]==password[i+1]) return false;

        }
        if(password.length()>=8 && low && up && dig && sp ) return true;
        return false;

    }
};
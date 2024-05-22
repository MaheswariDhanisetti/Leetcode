class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long long temp=x;
        long long  s=0;
        while(x>0){
            s=s*10+(x%10);
            x=x/10;
        }

        return (temp==s);
    }
};
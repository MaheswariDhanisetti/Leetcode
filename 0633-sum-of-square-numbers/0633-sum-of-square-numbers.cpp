class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int a=0,b=static_cast<int>(sqrt(c));
        while(a<=b){
            long long int  val=static_cast<long long int>(a) * a + static_cast<long long int>(b) * b;
            if(val==c) return true;
            if(val<c){
                a++;
            }
            if(val>c){
                b--;
            }
        }
        return false;
    }
};
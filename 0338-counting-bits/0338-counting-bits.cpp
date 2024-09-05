class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;

        for(int i=1;i<=n;i++){

            //counting no of bits
            int noOfBits =  log2(i);

            //calculate the range in which the number falls;
            int currRange = pow(2, noOfBits);

            //the noof bits of currnumber is 1+ no of bits in number = currnumber - currRange
            //ex:- ones(10) = 1+ ones( 10 - 8 )
            //how 8 ; 8= pow(2,no_of_bits(10))

            dp[i]=(1+ dp[i-currRange]);
        }

        return dp;

    }
};
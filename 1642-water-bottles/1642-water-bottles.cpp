class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans=0;
        int c=0;
        while(numBottles>0)
        {
           ans++;
           c++;
           if(c==numExchange){
               numBottles++;
               c=0;
           }
           numBottles--;

        }
        return ans;


    }
};
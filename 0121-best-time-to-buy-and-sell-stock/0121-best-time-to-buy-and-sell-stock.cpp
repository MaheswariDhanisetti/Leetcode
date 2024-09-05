class Solution {
public:
    int maxProfit(vector<int>& prices) {
           
        
        int currLow=prices[0];
        int res=0;
        for(int i=1;i<prices.size();i++){
            res=max(res, prices[i]-currLow);
            currLow=min(currLow,prices[i]);
        }

        return res;

    }
};
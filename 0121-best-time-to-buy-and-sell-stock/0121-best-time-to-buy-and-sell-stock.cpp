class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;

        int currmin=prices[0];

        for(int i=1;i<prices.size();i++){

            res=max(res, prices[i]-currmin);
            currmin=min(currmin,prices[i]);
        }
        return res;
    }
};
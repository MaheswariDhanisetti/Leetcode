class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int tot = 0;

        int prev = 0;

        for(int i = 1;i<colors.size();i++)
        {
            if(colors[i] == colors[prev]){
                tot += min(neededTime[i] , neededTime[prev]);
                if(neededTime[prev] <= neededTime[i]){
                    prev = i;
                }
            }
            else{
                prev = i;
            }

        }

        return tot;

    }
};
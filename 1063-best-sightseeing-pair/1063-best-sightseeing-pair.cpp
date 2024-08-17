class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>ival;
        vector<int>jval;

        for(int i=0;i<values.size();i++){
            ival.push_back(values[i]+i);
            jval.push_back(values[i]-i);
        }

        int currmax=ival[0];
        int res=0;

        for(int j=1;j<jval.size();j++){

            res=max(res, currmax+jval[j]);
            currmax=max(currmax,ival[j]);
        }
        return res;
    }
};
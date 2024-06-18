class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum=0;
        for(int i=0;i<worker.size();i++)
        {
            int val=0;
            for(int j=0;j<difficulty.size();j++)
            {
                if(worker[i]>=difficulty[j])
                {
                    val=max(val,profit[j]);
                }
            }
            sum+=val;
        }
        return sum;
    }
};
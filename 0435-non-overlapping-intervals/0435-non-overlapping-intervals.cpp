class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size() , ans = 0;

        sort(intervals.begin() , intervals.end() , [](vector<int>&a , vector<int>&b){
            return a[1] < b[1];
        });

        int prev_fin = INT_MIN;

        for(int i = 0;i<intervals.size();i++)
        {
            if(intervals[i][0] >= prev_fin)
            {
                ans++;
                prev_fin = intervals[i][1];
            }
        }

        return n-ans;

    }
};
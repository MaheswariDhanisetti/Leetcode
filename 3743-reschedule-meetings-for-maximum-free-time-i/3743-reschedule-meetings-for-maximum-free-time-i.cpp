class Solution {
public:

    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();

        vector<int>gps;

        gps.push_back(startTime[0]-0);

        for(int i=1;i<n;i++){
            gps.push_back(startTime[i]-endTime[i-1]);
        }

        gps.push_back(eventTime-endTime[n-1]);

        k= k+1;

        int curr = 0;

        int maxi = 0;

        for(int i=0;i<gps.size();i++){

            curr += gps[i];
            
            //erasing
            if(i>=k){
                curr -= gps[i-k];
            }

            //considering to answr start from k-1;

            if(i>=k-1){
                maxi = max(maxi , curr);
            }

            // cout<<gps[i]<<" ";

        }

        return maxi;
        
    }
};
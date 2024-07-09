class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double avg=0;
        int currtime=1;
        for(int i=0;i<customers.size();i++){
            currtime= max(currtime,customers[i][0]);
            currtime+=customers[i][1];
            avg+= currtime-customers[i][0];
        }

        return avg/customers.size();
    }
};
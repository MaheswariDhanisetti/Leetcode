class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        //idea or approach :- sort the array of times as basic fact is that the  difference between adjacent times is always minimum
        //-->findout minutes value of given time 
        //-->then find the adjacent difference between two minutes 
        //-->handle an edge case as time is cyclic so consider the differenc of last and firts times in sorted array.
        //--> when handling edge case you have to add 1440 minutes (24hrs in minutes) to lowest minutes and subtract the maximum miuntes from it.
        //-->return the minimum values of all adjacent values

        sort(timePoints.begin(),timePoints.end());
        int ans=INT_MAX;
        int val;
        timePoints.push_back(timePoints[0]);

        for(int i=0;i<timePoints.size()-1;i++){
            string hrs1 = timePoints[i].substr(0,2);
            string mins1 = timePoints[i].substr(3,2);
            string hrs2 = timePoints[i+1].substr(0,2);
            string mins2 = timePoints[i+1].substr(3,2);

            if(i==timePoints.size()-2){
                val = abs( (stoi(hrs2)*60+stoi(mins2)) + 1440 -  (stoi(hrs1)*60+stoi(mins1)) );
            }
            else 
                val= (stoi(hrs2)*60+stoi(mins2)) - (stoi(hrs1)*60+stoi(mins1));
            ans=min(ans,val);

        }

        
        return ans;
    }
};
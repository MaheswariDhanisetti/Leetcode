class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        for ( int i = 0 ; i < customers.size() ; i++ ){
            if( grumpy[i] == 0 ){
                sum+=customers[i];
            }
        }
        
        int temp = 0 ;
        for(int i = 0 ; i<=customers.size()-minutes ; i++ ){
            int val = 0;
            for( int j = i ; j<i+minutes && j<customers.size() ; j++ ){
                if(grumpy[j]==1){
                    val+=customers[j];
                }
            }
            temp = max(temp,val);
        }
        return sum+temp;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        unordered_map<int,int>mp;

        for(int i=0;i<bills.size();i++){
            
            if(bills[i]>5){
               int tens=(bills[i]-5)/10;
               int fives=((bills[i]-5)%10==0)?0:1;
               if(tens<=mp[10]){
                  
                  mp[10]-=tens;
                  tens=0;
               }
               else{
                  tens-=mp[10];
                  fives+= 2*tens;
               }

               if(fives<=mp[5]){
                  
                  mp[5]-=fives;
                  fives=0;
               }
               else{
                  return false;
               }
            }
            mp[bills[i]]++;

        }

        return true;
    }
};
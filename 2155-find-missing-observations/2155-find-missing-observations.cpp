class Solution {
public:

    
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        //calculated sum of the m elements 
        long long sum = accumulate(rolls.begin(),rolls.end(),0);
        long long val= mean*(n+ rolls.size());
        
        //sum of remaining n elements
        val-=sum;
        
        vector<int>v(n);
        long long avg = val/n;
        long long rem = val - avg*n ; 

        for(int i=0;i<n;i++){
            v[i]= avg ;

            if(rem > 0 ){

                if((6-v[i])>=rem){
                    v[i]+=rem;
                    rem=0;
                }
                else{
                    rem-=(6-v[i]);
                    v[i]=6;
                }
            }

        }

        
        if(rem!=0 || val<0 || val>n*6 || (val/n)<1) return {};
        return v;
    }
};
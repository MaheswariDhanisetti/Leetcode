class Solution {
public:
    int numberOfWays(string corridor) {

        int seats = 0 , plants = 0;

        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i]=='S') seats++;
        }

        if(seats%2==1 or seats <= 0) return 0;

        const int mod = 1e9+7;
        
        int curr = 1 , tot = 1;

        seats = 0;

        for(int i =0;i<corridor.size();i++)
        {
            if(corridor[i]=='S'){
                seats++;
            }
            
            if(seats%2==0 and seats > 0)
            {
                if(corridor[i]=='P')
                {
                    curr++;
                }
            }
            else{
                // cout<<i<<" curr : "<<curr<<" tot : "<<tot<<" tot after : ";
                tot = (tot%mod*curr%mod)%mod;
                // cout<<tot<<endl;
                curr = 1;
            }
            
        }
        return tot;
    }
};

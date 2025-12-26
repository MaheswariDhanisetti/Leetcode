class Solution {
private:
public:
    int bestClosingTime(string customers) {
        int n=0,y=0;
        int ans=INT_MAX;
        int res;
        for(int i=0;i<customers.size();i++)
        {
           if(customers[i]=='Y') y++;          
        }
        customers+='Y';
        for(int i=0;i<customers.size();i++)
        {
            int p=0;
            if(customers[i]=='Y'){
                p=n+y;
                y--;
            }
            else{
                p=n+y;
                n++;
            }
            if(p<ans)
            {
                ans=p;
                res=i;
            }
        }
       
        
        return res;

    }
};
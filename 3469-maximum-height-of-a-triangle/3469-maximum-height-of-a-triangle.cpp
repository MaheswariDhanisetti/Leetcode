class Solution {
public:
    int maxhigh(int tb,int tr){
        int ans=0;
        for(int i=1;tb>0 || tr>0;++i){
            if(i%2==0 && tr-i >=0){
                tr-=i;
                ans++;
            }
            else if(i%2==1 && tb-i>=0){
                tb-=i;
                ans++;
            }
            else break;
            
        }
        // return (tr<0 || tb<0 )? ans-1:ans;
        return ans;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        

        //blue as start
        int bluehigh=maxhigh(blue,red);

        //red as start 
        int redhigh=maxhigh(red,blue);

        return max(bluehigh,redhigh);

        

        
    }
};
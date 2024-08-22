class Solution {
public:
    int findComplement(int num) {
        int ans=1;
        int i=0;
        int temp=num;
        while(num>0)
        {
            ans= ans|(1<<i);
            num=num>>1;
            i++;
        }
        // cout<<ans<<" "<<temp;
        return temp^ans;
    }
};
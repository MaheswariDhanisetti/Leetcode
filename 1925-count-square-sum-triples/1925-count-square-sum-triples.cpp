class Solution {
public:
    int countTriples(int n) {

        int ans = 0;

        for(int i = 1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                int curr = i*i + j*j;
                int temp = sqrt(curr);

                if(temp*temp == curr and temp<=n)
                {
                    ans++;
                    // cout<<i<<" "<<j<<" "<<curr<<endl;
                }
            }
        }

        return ans;
        
    }
};
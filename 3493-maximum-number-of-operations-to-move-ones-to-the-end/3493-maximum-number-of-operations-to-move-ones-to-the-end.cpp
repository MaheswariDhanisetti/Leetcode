class Solution {
public:
    int maxOperations(string s) {
        
        int ones = 0 , ans =0 ;

        for(int i=0;i<s.size();i++)
        {
            bool chk = 0;
            while(i<s.size() and s[i]=='0')
            {
                i++;
                chk = 1;
            }

            if(chk)  ans += ones;

            if(i<s.size() and s[i]=='1') ones++;

        }

        return ans;

    }
};
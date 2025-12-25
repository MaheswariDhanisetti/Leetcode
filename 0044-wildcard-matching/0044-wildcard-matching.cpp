class Solution {
public:

    bool solve(string s , string p , int i , int j,int cnt)
    {
        if(i >= s.size()) return cnt==0;
        if(j>=p.size()) return i>=s.size();


        bool res = false;

        if(p[j]=='*')
        {
            for(int k = i;k<=s.size();k++)
            {
                res |= solve(s,p ,k,j+1,cnt);
            }
        }
        else if(p[j]=='?')
        {
            res |= solve(s,p,i+1,j+1,cnt-1);
        }
        else{
            if(s[i]==p[j]) res |= solve(s,p,i+1,j+1,cnt-1);
        }

        return res;
    }
    bool isMatch(string s, string p) {

        int cnt = 0;

        for(int j =0;j<p.size();j++)
        {
            if(p[j]!='*') cnt++;
        }
        return solve(s , p , 0, 0,cnt);
        
    }
};
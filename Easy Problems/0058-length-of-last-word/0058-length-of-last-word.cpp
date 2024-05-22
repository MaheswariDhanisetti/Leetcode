class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int c=0,j;
        for(int i=s.size()-1;i>=0;i--)
        {

            if(s[i]!=' '){
               j=i;
               while( j>=0 && s[j]!=' '){
                   c++;
                   j--;
               }
               break;
            }
        }
        return c;
    }
};
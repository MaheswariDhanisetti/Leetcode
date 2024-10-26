class Solution {
public:
    int possibleStringCount(string word) {
        int ans=0,cnt=0;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                cnt++;
            }
            else{
                ans+=cnt;
                cnt=0;
            }

        }

        return ans+cnt+1;
    }
};
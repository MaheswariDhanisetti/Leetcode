class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int i=0,j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[j]){
                j++;
            }
            if(j==s.size()) return 0;
        }

        return t.size()-j;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        

        string st=strs[0],end=strs[strs.size()-1];
        string ans="";

        int n=min(st.size(),end.size()); 

        for(int i=0;i<n;i++){
            if(st[i]==end[i]) ans+=st[i];
            else break;
            
        }

        return ans;
    }
};
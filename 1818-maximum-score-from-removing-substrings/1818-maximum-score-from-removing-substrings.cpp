class Solution {
    private:
    void findMax(string s,int &ans,int x,string sub,stack<char>&st){
        for(int i=0;i<s.size();i++){
            if(s[i]==sub[1] && !st.empty() && st.top()==sub[0]){
                ans+=x;
                st.pop();
            }
            else st.push(s[i]);
        }
    }
public:
    int maximumGain(string s, int x, int y) {
        
        stack<char>st;
        string sub1,sub2;
        int ans=0,v1,v2;
        string s1,s2;

        if(x>y){
            v1=x;
            s1="ab";
            v2=y;
            s2="ba";
        }
        else{
            v1=y;
            v2=x;
            s1="ba";
            s2="ab";
        }

       
            findMax(s,ans,v1,s1,st);
        
            string temp="";
            while(!st.empty()) {
                temp+=st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            findMax(temp,ans,v2,s2,st);
      
        return ans;
    }
};
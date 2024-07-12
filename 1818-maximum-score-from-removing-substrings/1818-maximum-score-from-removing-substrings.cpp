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
        int ans=0;

        if(x>y){
            findMax(s,ans,x,"ab",st);
        
            string temp="";
            while(!st.empty()) {
                temp+=st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            findMax(temp,ans,y,"ba",st);
        }

        else{
            findMax(s,ans,y,"ba",st);
        
            string temp="";
            while(!st.empty()) {
                temp+=st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            findMax(temp,ans,x,"ab",st);
        }

        

        return ans;
    }
};
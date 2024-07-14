class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& h, string d) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<positions.size();i++){
            mp[positions[i]]=i+1;
        }

        sort(positions.begin(),positions.end());
        stack<int>st;

        for(int i=0;i<positions.size();i++){
            
            if(!st.empty() && d[mp[st.top()]-1]=='R' && d[mp[positions[i]]-1]=='L' ){

              while(!st.empty() && d[mp[st.top()]-1]=='R' && d[mp[positions[i]]-1]=='L'){
                if(h[mp[st.top()]-1]>h[mp[positions[i]]-1]){
                    h[mp[st.top()]-1]--;
                    h[mp[positions[i]]-1]=0;
                    break;

                }
                else if(h[mp[st.top()]-1]<h[mp[positions[i]]-1]){
                    h[mp[st.top()]-1]=0;
                    st.pop();
                    h[mp[positions[i]]-1]--;
                }
                else{
                    h[mp[st.top()]-1]=0;
                    h[mp[positions[i]]-1]=0;
                    st.pop();
                    break;
                }
              }
            }
            else{
                st.push(positions[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<h.size();i++){
            if(h[i]>0) ans.push_back(h[i]);
        }
        return ans;

    }
};
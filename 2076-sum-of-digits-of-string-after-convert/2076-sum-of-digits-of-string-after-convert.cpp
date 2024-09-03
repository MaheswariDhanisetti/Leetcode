class Solution {
public:
    
  

    int getLucky(string s, int k) {
        
        string res="";

        for(int i=0;i<s.size();i++){
            int temp= s[i]-'a'+1;
            res+= to_string(temp);
            // cout<<s[i]<<" :"<<temp<<" : "<<res<<endl;
        }
        
        while(k--){
            
            long long temp=0;
            for(int i=0;i<res.size();i++){
                temp+=(res[i]-'0');
            }
            res=to_string(temp);
            // cout<<temp<<" ";
        }

        return stoi(res);
        

    }
};
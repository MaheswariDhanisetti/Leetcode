class Solution {
public:
    bool hasSameDigits(string s) {


        string temp = "";


        while(s.size()>2){

            temp ="";

            for(int i=1;i<s.size();i++){
                int curr = (s[i]-'0' + s[i-1]-'0')%10;
                
                temp += to_string(curr);
                // cout<<curr<<" ";
            }

            s=temp;

            // cout<<s<<" ";
            
        }

        // cout<<s<<" ";

        return (s[0]==s[1]);
        
    }
};
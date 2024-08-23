class Solution {
public:
    string fractionAddition(string expression) {
        
        int prevnum=0,prevden=1;
        int i=0;

        while(i<expression.size() and expression[i]>='0' and expression[i]<='9'){
           
            int temp=0;

            while(i<expression.size() and expression[i]>='0' and expression[i]<='9'){
                temp=temp*10 + (expression[i]-'0');
                i++;
            }

            i++;
            prevnum=temp;
            temp=0;

            while(i<expression.size() and expression[i]>='0' and expression[i]<='9'){
                temp=temp*10 + (expression[i]-'0');
                i++;
            }

            prevden=temp;

        }

        while(i<expression.size()){
            if(expression[i]=='-' || expression[i]=='+'){
                char ch=expression[i];
                int currnum=0;
                int currden=0;
                int temp=0;
                i++;
                while(i<expression.size() and expression[i]>='0' and expression[i]<='9'){
                    temp=temp*10 + (expression[i]-'0');
                    i++;
                }
                // cout<<temp<<" ";
                i++;
                currnum=temp;
                temp=0;

                while(i<expression.size() and expression[i]>='0' and expression[i]<='9'){
                    temp=temp*10 + (expression[i]-'0');
                    i++;
                }
                
                // cout<<temp<<endl;
                i--;


                currden=temp;
                if(prevnum==0){
                    prevden=1;
                }

                int gcdOfDen=__gcd(currden,prevden);
                int lcmOfDen=  (currden*prevden)/gcdOfDen;

                currnum*= lcmOfDen/currden;
                prevnum*= lcmOfDen/prevden;

                // cout<<lcmOfDen<<" "<<prevnum<<" "<<currnum<<" :";

                if(ch=='+'){
                    prevnum = prevnum+currnum;
                    // cout<<"--"<<prevnum<<endl;
                }
                else{
                    prevnum= prevnum-currnum;
                }

                prevden=lcmOfDen;
                // cout<<prevnum<<" "<<prevden<<endl;

            }

            i++;
   
        }

        
        if(prevnum==0){
            prevden=1;
        }

        int comgcd=__gcd(abs(prevnum),abs(prevden));
        prevnum/=comgcd;
        prevden/=comgcd;

        string ans= to_string(prevnum)+"/"+to_string(prevden);
        return ans;



    }
};
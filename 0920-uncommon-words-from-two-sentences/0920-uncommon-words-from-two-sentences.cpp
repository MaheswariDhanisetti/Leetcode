class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       
       //using an unordered map to store the frequence of words in sentence1
       unordered_map<string , int>ump;

       //traversing through sentence1
       string temp="";
       for(int i=0;i<s1.size();i++){
            if(s1[i]==' ' and temp!=""){
                ump[temp]++;
                temp="";
            }
            else{
                temp+=s1[i];
            }
       }

       if(temp!="") ump[temp]++;
       temp="";
       for(int i=0;i<s2.size();i++){
            if(s2[i]==' ' and temp!=""){
                ump[temp]++;
                temp="";
            }
            else{
                temp+=s2[i];
            }
       }
       if(temp!="") ump[temp]++;

       vector<string>res;
       for(auto it:ump){
            if(it.second==1) res.push_back(it.first);
        // cout<<it.first<<" "<<it.second<<endl;
       }

       return res;


    }
};
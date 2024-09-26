class Solution {
public:

    void dfs(string &digits,int idx,unordered_map<char,string>&mp,vector<string>&ans,string curr){

        //if you reached the end of sequence just store your current string or sequence of charcters 
        if(idx>=digits.size()){
            ans.push_back(curr);
        } 

        //traverse in all correspondingncharacters of a digit and call dfs for next digit in sequence 
        for(int i=0;i<mp[digits[idx]].size();i++){
            dfs(digits,idx+1,mp,ans,curr+mp[digits[idx]][i]);
        }
    }
    vector<string> letterCombinations(string digits) {

        //maintaining a hashmap to map each digit to its corresponnding characters
        unordered_map<char,string>mp;
        mp[' ']="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";


        vector<string>ans;


        if(digits=="") return ans;

        //call for dfs function starting from first digit in the sequence
        dfs(digits,0,mp,ans,"");
        return ans;

    }
};
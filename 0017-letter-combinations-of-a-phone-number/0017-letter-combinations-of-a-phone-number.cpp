class Solution {
public:

    void dfs(string &digits,int idx,unordered_map<char,string>&mp,vector<string>&ans,string curr){

        if(idx>=digits.size()){
            ans.push_back(curr);
        } 
        for(int i=0;i<mp[digits[idx]].size();i++){
            dfs(digits,idx+1,mp,ans,curr+mp[digits[idx]][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
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
        dfs(digits,0,mp,ans,"");
        return ans;

    }
};
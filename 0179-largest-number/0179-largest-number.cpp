class Solution {
public:

    static bool cmp(int a,int b){
        
        string s1=to_string(a);
        string s2=to_string(b);

        for(int i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i]>s2[i]) return true; 
            else if(s1[i]<s2[i]) return false;
        }

        if(s1+s2 > s2+s1) return true;
        return false;
    }

    string largestNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end(),cmp);

        for(int i:nums) cout<<i<<" ";

        string res="";

        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
        }

        while(res.size()>1 and res[0]=='0'){
            if(res[0]=='0') res.erase(0,1);
        }
        return res;
    }
};
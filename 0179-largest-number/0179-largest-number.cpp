class Solution {
public:

    string largestNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end(), [](int a,int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });

        // for(int i:nums) cout<<i<<" ";

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
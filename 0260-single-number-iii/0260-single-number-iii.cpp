class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xorsm=0,mask=1;
        for(auto &ele:nums) xorsm^=ele;
        

        while (not (xorsm & mask)) mask <<= 1;

        int first=0,num2=0;
        for (auto &num: nums)
		if (num & mask) first ^= num;
        return {first,xorsm^first};

    }
};
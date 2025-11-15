class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        unordered_map<int,int>m1 , m2;

        int res = INT_MAX;

        for(int i = 0;i<nums.size();i++)
        {
            if(m1.count(nums[i])==0){
                m1[nums[i]] = i;
            }
            else if(m2.count(nums[i])==0)
            {
                m2[nums[i]] = i;
            }
            else{
                int dist = abs(m1[nums[i]]-m2[nums[i]])+abs(m2[nums[i]]-i)+abs(i-m1[nums[i]]);
                res = min(res , dist);
                m1[nums[i]] = m2[nums[i]];
                m2[nums[i]] = i;
            }
        }

        return res==INT_MAX?-1:res;

    }
};
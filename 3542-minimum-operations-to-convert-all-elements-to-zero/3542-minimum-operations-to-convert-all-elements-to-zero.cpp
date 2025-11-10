class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        stack<int>st;

        vector<int>pse(n,-1);
    
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() and nums[st.top()]>=nums[i]) st.pop();

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }

        unordered_map<int ,int>mp;

        int ans = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0) continue;

            if(mp.count(nums[i])<=0 or mp[nums[i]]>i){
                ans++;
            }
            
            mp[nums[i]] = pse[i]+1;

        }

        return ans;
    }
};

//  2  2 4 5 4 4 6 4 2 
//  0  1 2 3 4 5 6 7 8 - idx
// -1 -1 1 1 1 1 5 1 -1  - pse
// 0  0  0  1  0  0  1 1  1 - ans
// p cov
// 2 - 0
// 6 - 6
// 4 - 2
// 5 - 2
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size() , tmp = x;

        vector<int>res;

        unordered_map<int,int>mp;

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
            
            if(i>=k){
                mp[nums[i-k]]--;
            }

            tmp = x;

            for(auto it:mp){
                pq.push({it.second, it.first});
            }

            int curr = 0;

            while(!pq.empty() and tmp > 0){
                curr+=(pq.top().first*pq.top().second);
                pq.pop();
                tmp--;
            }

            while(!pq.empty()) pq.pop();

            if(i>=k-1){
                res.push_back(curr);
            }

        }

        return res;
    }
};
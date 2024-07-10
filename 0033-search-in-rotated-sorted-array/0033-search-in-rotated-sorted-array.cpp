class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it=find(begin(nums),end(nums),target);
        int idx=distance(nums.begin(),it);
        if(it==nums.end()) return -1;
        return idx;
    }
};
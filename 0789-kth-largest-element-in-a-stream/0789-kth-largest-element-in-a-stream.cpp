class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        
        sort(rbegin(nums),rend(nums));

        for(int i=0;i<nums.size() && i<k;i++){
            pq.push(nums[i]);
        }
        this->k=k;

    }
    
    int add(int val) {
        
        if(pq.empty() || pq.size()<k){
            pq.push(val);
        }
        else if(!pq.empty() && val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
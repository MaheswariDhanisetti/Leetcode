class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long totSum = accumulate(chalk.begin(),chalk.end(),0LL);

        int rem = k%totSum;

        //calculating prefix sum 
        vector<long long>pre;
        pre.push_back(chalk[0]);

        for(int i=1;i<chalk.size();i++){
            pre.push_back(pre.back()+chalk[i]);
        }

        //binary search approach to find the student who lacks of chalk in O(logn) time
        int low=0,high=chalk.size()-1;

        while(low<=high){

            int mid = (low+high)/2;

            // if preix of mid is greater than remaining chalks
            if(pre[mid]>rem){
                high=mid-1;
            } 
            else if(pre[mid]<rem){
                low=mid+1;
            }
            else{
                return mid+1;
            }
        }

        return low;

    }
};
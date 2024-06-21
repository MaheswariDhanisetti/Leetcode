class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<(long long)m*k) return -1;
        int st=*min_element(b.begin(),b.end());
        int end=*max_element(b.begin(),b.end());
        int mid;
        while(st<=end){

            mid=(end+st)/2;
            int total=0,cnt=0;

            for(int i=0;i<b.size();i++){
                if(b[i]<=mid){
                    cnt++;
                }
                else{
                    total+= cnt/k;
                    cnt=0;
                }
            }
            total+=cnt/k;
            
            if(total>=m){
                end=mid-1;
            }
            if(total<m){
                st=mid+1;
            }

        }
        return st;
        
    }
};
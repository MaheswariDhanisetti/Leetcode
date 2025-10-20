class Solution {
public:

    bool poss(long long mid ,vector<long long>pref , vector<int>&stations ,int  k , int  r){
      
        long long req = 0;

        vector<long long>temp(pref.size() ,0);
        
        for(int i = 0;i<pref.size();i++){
            if(i >0) temp[i] += temp[i-1];
            
            pref[i] += temp[i];

            if(pref[i] < mid){
                long  long diff = mid - pref[i];
                temp[i]+= diff;
                req += diff;
                if(i+(2*r)+1 < temp.size()) temp[i+(2*r)+1] -= diff;
            }

        }

        

        if(req <= k) return true;

        return false;

    }

    long long maxPower(vector<int>& stations, int r, int k) {

        int n = stations.size();
        
        vector<long long>pref(n , 0);

        pref[0] = stations[0];

        if(r+1 < n) pref[r+1] -= stations[0];

        for(int i=1;i<n;i++){

            pref[i] += pref[i-1]+stations[i];

            if( (i+r+1) < n){
                pref[i+r+1] -= stations[i];
            }
            
        }

        long long temp = stations[n-1];

        if(n-r-2 >=0) pref[n-r-2] -= temp;
        
        long long mini = pref[n-1] , maxi = pref[n-1];

        for(int i = n-2 ; i>=0;i--){

            pref[i] += temp;

            temp+= stations[i];

            if( (i-r-1) >=0 ){
                pref[i-r-1] -= temp;
            }

            mini = min(mini , pref[i]);
            maxi = max(maxi ,pref[i]);

        }

        long long low = mini , high = maxi+k;

        long long ans = low;

        while(low<=high){

            long long mid = low + (high-low)/2;

            if(poss(mid , pref ,stations ,k,r)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        } 

        return ans;

    }
};


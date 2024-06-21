class Solution {
private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) return true;
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<(long long)m*k) return -1;
        int st=*min_element(b.begin(),b.end());
        int end=*max_element(b.begin(),b.end());
        int mid;
        while(st<=end){

            mid=st+(end-st)/2;
            if (canMakeBouquets(b, m, k, mid)) {
                end = mid-1; 
            } else {
                st = mid + 1;
            }
        }
        return st;
        
    }
};
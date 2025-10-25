class Solution {
public:
    int totalMoney(int n) {
        
        int full = n/7;
        int addon = (full-1)*(full)/2;
        int rem = n%7;
        
        int res = full * 28 + addon*7 + (rem * (rem+1)/2) + full*rem;

        return res;

    }
};
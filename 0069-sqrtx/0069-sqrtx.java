class Solution {
    public int mySqrt(int x) {

        int i=1;
        while(i<=x/i){
            if(x/i==i) return i;
            i++;
        }

        return i-1;
    }
}
class Solution {
public:
    int passThePillow(int n, int time) {
        
            int rem=time%(n-1); //remaining passes after complete cycles
            if((time/(n-1))%2==0) return rem+1; //in forward direction
            else return (n-rem); //in backward direction            
    }
};
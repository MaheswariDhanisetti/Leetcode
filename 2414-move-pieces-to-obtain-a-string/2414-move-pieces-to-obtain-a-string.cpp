class Solution {
public:
    bool canChange(string start, string target) {
        
        int i=0,j=0;
        int n=start.size();

        while(i<n or j<n){
            

            //ignoring spaces i.e., '_' in the strings
            while(start[i]=='_') i++;
            while(target[j]=='_') j++;

            //if both strings dont have same pattern of L and R's then we cant crossover them to turn start into target
            if(start[i]!=target[j]) return false;

            //as we can only move L to left so the L position in start should be greater than or equal to the L position in target string
            if(start[i]=='L' and i<j) return false;

            // as we can only move right when we encounter an R so the position of R in the start string must be less than or equal to R position in target string
            if(start[i]=='R' and j<i) return false;

            i++;
            j++;
        }


        return true;
    }
};
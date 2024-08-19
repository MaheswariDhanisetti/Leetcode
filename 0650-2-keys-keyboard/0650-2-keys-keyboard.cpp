class Solution {
public:
     bool Isprime(int n){
        if(n==1)return false;
        for(int i = 2; i * i <= n ; i++){
            if(n % i == 0)return false;
        }
        return true;
    }
    int minSteps(int n) {
        vector<bool>primes(n+1,false);
        for(int i = 1  ; i <= n ; i++){
            if(Isprime(i)) primes[i] = true;
        }

        int ans = 0;
        for(int i = 2 ; i <= n * n ; i++){
            while(n % i == 0 and primes[i]){
                ans+=i;
                n/=i;
            }
        }
        return ans;
    }
};
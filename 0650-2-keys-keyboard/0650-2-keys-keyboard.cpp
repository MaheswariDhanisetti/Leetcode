class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int d = 2; d < sqrt(n) + 1; ++d) {
            if (n % d == 0) return d + minSteps(n / d);
        }
        return n;
    }
};
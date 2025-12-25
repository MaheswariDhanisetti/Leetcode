class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        bool res = false;

        if (p[j] == '*') {
            // match empty OR match one char
            res = solve(s, p, i, j + 1) || 
                  (i < s.size() && solve(s, p, i + 1, j));
        }
        else if (i < s.size() && (p[j] == '?' || p[j] == s[i])) {
            res = solve(s, p, i + 1, j + 1);
        }

        return dp[i][j] = res;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};

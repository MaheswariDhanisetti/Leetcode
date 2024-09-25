class Solution {
    int solve(string s1, string s2){
        int len = min(s1.length(), s2.length());
        for(int i = 0; i<len; i++) if(s1[i]!=s2[i])return i;
        return len;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> sArr1, sArr2;
        for(auto &num:arr1)sArr1.push_back(to_string(num));
        for(auto &num:arr2)sArr2.push_back(to_string(num));
        sort(sArr1.begin(), sArr1.end());
        sort(sArr2.begin(), sArr2.end());
        int i = 0, j = 0, ans = 0;
        while (i < arr1.size() && j < arr2.size()) {
            ans = max(ans, solve(sArr1[i], sArr2[j]));
            if (sArr1[i] < sArr2[j]) i++;
            else j++;
        }
        return ans;
    }
};
class Solution {
    int solve(string s1, string s2){
        int len = min(s1.length(), s2.length());
        for(int i = 0; i<len; i++) if(s1[i]!=s2[i])return i;
        return len;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> a1, a2;
        for(int &num:arr1)a1.push_back(to_string(num));
        for(int &num:arr2)a2.push_back(to_string(num));
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        int i = 0, j = 0, ans = 0;
        while (i < arr1.size() && j < arr2.size()) {
            ans = max(ans, solve(a1[i], a2[j]));
            if (a1[i] < a2[j]) i++;
            else j++;
        }
        return ans;
    }
};
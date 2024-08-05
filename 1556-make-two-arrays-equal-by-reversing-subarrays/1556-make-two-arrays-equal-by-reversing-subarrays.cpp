class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
};
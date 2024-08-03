class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
};
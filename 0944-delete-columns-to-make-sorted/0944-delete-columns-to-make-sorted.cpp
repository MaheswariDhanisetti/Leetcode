class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int ans = 0;
        for(int i =0 ;i<strs[0].size();i++){
            string curr = "";

            for(int j = 0;j<strs.size();j++)
            {
                curr += strs[j][i];
            }
            string temp = curr;

            sort(temp.begin() , temp.end());

            if(temp!=curr) ans++;
        }

        return ans;
    }
};
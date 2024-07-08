class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(i+1);
        }
        vector<int>::iterator it;
        it = v.begin()+k;
        while(v.size()>1)
        {
           for(int i=0;i<k-1;i++)
           {
               v.push_back(v[i]);
           }
           v.erase(v.begin(),v.begin()+k);
        }
        return v[0];
    
    }
};
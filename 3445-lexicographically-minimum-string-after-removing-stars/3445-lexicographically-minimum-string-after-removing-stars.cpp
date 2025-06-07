class Solution {
public:
    string clearStars(string s) {
        
        
        vector<int>v;
        int idx;
        
         auto cmp = [](pair<char, int> left, pair<char, int> right) {
            if (left.first == right.first) {
                return left.second < right.second;  // Keep the latest index first
            }
            return left.first > right.first;  // Min-heap based on character
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    idx=pq.top().second;
                    v.push_back(idx);
                    pq.pop();
                }
                v.push_back(i);
               
            }
            else{
                pq.push({s[i],i});
                
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        
        for(int i=0;i<v.size();i++){
            s.erase(s.begin()+v[i]);
        }
        return s;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>st;

        for(int i=0;i<asteroids.size();i++){

            bool chk = true;

            while(!st.empty() and st.top() >0 and asteroids[i]<0  ){
                if(st.top() < abs(asteroids[i])) st.pop();
                else if(st.top() == abs(asteroids[i])){
                    st.pop();
                    chk = false;
                    break;
                }
                else{
                    chk = false;
                    break;
                }
            }

            if(chk == true){
                st.push(asteroids[i]);
            }

        }   

        vector<int>res;

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }     

        reverse(res.begin() , res.end());

        return res;
    }
};
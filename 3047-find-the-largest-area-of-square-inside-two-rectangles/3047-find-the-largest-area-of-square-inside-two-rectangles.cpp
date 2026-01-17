class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        long long max_side = 0;

        for(int i=0;i<bottomLeft.size();i++)
        {
            for(int j = i+1;j<bottomLeft.size();j++)
            {

                long long st1 = bottomLeft[i][0] , st2 = bottomLeft[j][0];
                long long en1 = topRight[i][0] , en2 = topRight[j][0];

                long long hz = min(en1,en2)-max(st1,st2);

                st1 = bottomLeft[i][1] , st2 = bottomLeft[j][1] , en1 = topRight[i][1] , en2 = topRight[j][1];

                long long vt = min(en1,en2)-max(st1,st2);

                max_side = max(max_side , min(hz,vt));

            }
        }

        return max_side*max_side;

    }
};



// [1,1][3,3]
//[2,2][4,4]

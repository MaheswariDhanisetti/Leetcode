class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(),verticalCut.end(), greater<int>());
        int total = 0;
        int horizontal = 1;
        int vertical = 1;
        int rowIndex = 0;
        int colIndex = 0;

        int x = horizontalCut.size();
        int y = verticalCut.size();

        while(rowIndex < x && colIndex < y)
        {
            if(horizontalCut[rowIndex] > verticalCut[colIndex])
            {
                total = total + (horizontalCut[rowIndex] * vertical);
                horizontal++;
                rowIndex++;
            }
            else
            {
                total = total + (verticalCut[colIndex] * horizontal);
                vertical++;
                colIndex++;
            }
        }
        while(rowIndex < x)
        {
            total = total + (horizontalCut[rowIndex] * vertical);
            rowIndex++;
        }
        while(colIndex < y)
        {
            total = total + (verticalCut[colIndex] * horizontal);
            colIndex++;
        }
        return total;
    }
};
// User function template in C++

class Solution {
  public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        // code here
        vector<vector<int>>grid(a,vector<int>(b));
        for(int i=0;i<a;i++){
            grid[i][b-1]=1;
        }
        for(int i=0;i<b;i++){
            grid[a-1][i]=1;
        }
        for(int i=a-2;i>=0;i--){
            for(int j=b-2;j>=0;j--){
                grid[i][j]=grid[i][j+1]+grid[i+1][j];
            }
        }
        return grid[0][0];
    }
};

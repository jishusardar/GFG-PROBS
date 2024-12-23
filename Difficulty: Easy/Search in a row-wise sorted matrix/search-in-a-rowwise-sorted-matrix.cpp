//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int row=-1;
        int n=mat.size();
        int m=mat[0].size()-1;
        for(int i=0;i<n;i++){
            if(mat[i][0]<=x&&mat[i][m]>=x){
                int start=0,end=m;
                 while(start<=end){
                 int mid=start+(end-start)/2;
                  if(mat[i][mid]==x)
                  return 1;
                  else if(mat[i][mid]>x)
                  end=mid-1;
                  else
                  start=mid+1;
                }
            }
        }
        if(row==-1)
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
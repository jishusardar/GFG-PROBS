//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    void Multiply(vector<vector<int> >& matrixA, vector<vector<int>>&matrixB) {
        // Code here
        vector<vector<int>>ans(matrixA.size());
        for(int i=0;i<matrixA.size();i++)
        {
            for(int k=0;k<matrixB[0].size();k++)
            {
            int sum=0;
            int j=0;
             for(int l=0;l<matrixB.size();l++){
                sum+=matrixB[l][k]*matrixA[i][j];
                j++;
             }
             ans[i].push_back(sum);
            }
        }
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                matrixA[i][j]=ans[i][j];
            }
        }
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrixA(n, vector<int>(n,0));
		vector<vector<int>> matrixB(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixA[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixB[i][j];
			}
		}
		Solution ob;
		ob.Multiply(matrixA, matrixB);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrixA[i][j] <<" ";
			cout << "\n";
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
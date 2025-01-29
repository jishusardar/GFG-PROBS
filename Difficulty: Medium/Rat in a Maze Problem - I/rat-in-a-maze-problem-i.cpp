//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    string dir="UDLR";
    bool valid(int i,int j,int n)
    {
        return i>=0&&j>=0&&i<n&&j<n;
    }
    void path(vector<vector<int>>&mat,vector<vector<bool>>&foot,int i,int j,vector<string>&ans,string &temp)
    {
        if(i==mat.size()-1&&j==mat.size()-1){
            ans.push_back(temp);
            return;
        }
        foot[i][j]=1;
        for(int k=0;k<4;k++){
            if(valid(i+row[k],j+col[k],mat.size())&&mat[i+row[k]][j+col[k]]&&!foot[i+row[k]][j+col[k]]){
                temp.push_back(dir[k]);
                path(mat,foot,i+row[k],j+col[k],ans,temp);
                temp.pop_back();
            }
        }
        foot[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<bool>>foot(n,vector<bool>(n,0));
        vector<string>ans;
        string temp;
        if(mat[0][0]==0||mat[n-1][n-1]==0){
            ans.push_back("-1");
            return ans;
        }
        path(mat,foot,0,0,ans,temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
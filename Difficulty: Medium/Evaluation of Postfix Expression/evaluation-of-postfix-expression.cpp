//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=="*"||arr[i]=="+"||arr[i]=="-"||arr[i]=="/"){
                int second=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                if(arr[i]=="*")
                st.push(first*second);
                else if(arr[i]=="/")
                st.push(first/second);
                else if(arr[i]=="-")
                st.push(first-second);
                else if(arr[i]=="+")
                st.push(first+second);
            }
            else{
                int num=stoi(arr[i]);
                st.push(num);
            }
        }
        return st.top();
        
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
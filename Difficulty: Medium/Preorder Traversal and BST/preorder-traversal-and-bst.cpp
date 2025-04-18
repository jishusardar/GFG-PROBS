//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void BST(int arr[],int N,int &index,int start,int end)
    {
        if(index==N||arr[index]<start||arr[index]>end){
            return;
        }
        int val=arr[index++];
        BST(arr,N,index,start,val);
        BST(arr,N,index,val,end);
    }
    int canRepresentBST(int arr[], int N) {
        // code here
        int index=0;
        BST(arr,N,index,INT_MIN,INT_MAX);
        return index==N;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
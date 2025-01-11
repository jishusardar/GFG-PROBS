//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxheight=0;
        int index=0;
        int miniheight=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxheight){
                maxheight=arr[i];
                index=i;
            }
        }
        int water=0;
        maxheight=0;
        for(int i=0;i<index;i++){
            if(arr[i]<maxheight){
                water+=(maxheight-arr[i]);
            }
            else
            maxheight=arr[i];
        }
        for(int i=arr.size()-1;i>index;i--){
            if(arr[i]<miniheight){
                water+=(miniheight-arr[i]);
            }
            else
            miniheight=arr[i];
        }
        return water;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
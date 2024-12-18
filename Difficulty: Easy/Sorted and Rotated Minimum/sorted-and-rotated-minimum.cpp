//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        if(arr.size()==1)
        return arr[0];
        else if(arr.size()==2)
        return arr[0]>arr[1]?arr[1]:arr[0];
        int start=0,end=arr.size()-1,ans=INT_MIN;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1])
            return arr[mid];
            else if(arr[mid]>=arr[0])
            start=mid+1;
            else{
                ans=arr[mid];
                end=mid-1;
            }
        }
        if(ans==INT_MIN)
        return arr[0];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
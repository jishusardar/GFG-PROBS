//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    void merge(vector<int>&arr,int start,int end,int &ans,int mid)
    {
        vector<int>temp(end-start+1);
        int left=start,right=mid+1,index=0;
        while(left<=mid&&right<=end)
        {
            if(arr[left]>arr[right]){
                temp[index]=arr[right];
                ans+=(mid-left+1);
                index++,right++;
            }
            else{
                temp[index]=arr[left];
                index++,left++;
            }
        }
        while(left<=mid)
        {
            temp[index]=arr[left];
            index++,left++;
        }
        while(right<=end){
            temp[index]=arr[right];
            index++,right++;
        }
        index=0;
        while(start<=end){
            arr[start]=temp[index];
            start++,index++;
        }
    }
    void mergesort(vector<int>&arr,int start,int end,int &ans)
    {
        if(start>=end)
        return;
        
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid,ans);
        mergesort(arr,mid+1,end,ans);
        merge(arr,start,end,ans,mid);
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int ans=0;
        mergesort(arr,0,arr.size()-1,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void Heapify(vector<int>&arr,int index,int n)
   {
       int largest=index;
       int left=2*index+1;
       int right=2*index+2;
       if(left<n&&arr[left]>arr[largest])
       largest=left;
       if(right<n&&arr[right]>arr[largest])
       largest=right;
       if(largest!=index){
           swap(arr[index],arr[largest]);
           Heapify(arr,largest,n);
       }
   }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        ans.push_back(a[i]);
        for(int i=0;i<b.size();i++)
        ans.push_back(b[i]);
        for(int i=(ans.size()/2)-1;i>=0;i--){
            Heapify(ans,i,ans.size());
        }
        return ans;
    }
};
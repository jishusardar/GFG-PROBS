class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int j=0,k=arr.size()-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<a){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=a&&arr[i]<=b){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]>b){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};
// User function template for C++
class Solution {
  public:
    /* Function to replace every element with the
    next greatest element */
    vector<int> nextGreatest(vector<int> arr) {
        // code here
        int maxi=max(arr[arr.size()-1],arr[arr.size()-2]);
        for(int i=arr.size()-3;i>=0;i--){
            if(maxi>arr[i]){
                arr[i]=maxi;
            }
            else{
                int num=maxi;
                maxi=arr[i];
                arr[i]=num;
            }
        }
        if(arr.size()>1)
        arr[arr.size()-2]=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        return arr;
    }
};
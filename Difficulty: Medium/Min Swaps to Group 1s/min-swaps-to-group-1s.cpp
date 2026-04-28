class Solution {
  public:
    int windowsize(vector<int>&arr){
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1)
            count++;
        }
        return count;
    }
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size();
        bool no1=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                no1=1;
                break;
            }
        }
        if(!no1)
        return -1;
        int size=windowsize(arr);
        int sum=0;
        for(int i=0;i<size-1;i++){
            if(arr[i])
            sum++;
        }
        int start=0,end=size-1;
        int maxi=INT_MIN;
        while(end<n){
            if(arr[end]==1)
            sum++;
            maxi=max(maxi,sum);
            if(arr[start]==1)
            sum--;
            start++,end++;
        }
        return size-maxi;
    }
};
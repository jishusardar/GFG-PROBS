class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        int start,end,size=0,index;
        vector<int>temp(n);
        temp[0]=arr[0];
        for(int i=1;i<n;i++){
            start=0,end=size,index=size+1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(temp[mid]==arr[i]){
                    index=mid;
                    break;
                }
                else if(temp[mid]<arr[i])
                start=mid+1;
                else{
                    index=mid;
                    end=mid-1;
                }
            }
            temp[index]=arr[i];
            size=max(size,index);
        }
        return size+1;
    }
};
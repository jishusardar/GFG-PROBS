class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int count1=0;
        int count0=0;
        int count2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
            count0++;
            if(arr[i]==1)
            count1++;
            if(arr[i]==2)
            count2++;
        }
        int i=0;
        while(count0--)
        arr[i++]=0;
        while(count1--)
        arr[i++]=1;
        while(count2--)
        arr[i++]=2;
    }
};
class Solution {
  public:
    void binSort(vector<int> &arr) {
        // code here
        int i=0,j=arr.size()-1;
        while(i<j){
            if(arr[i]==1){
                if(arr[j]==0){
                    swap(arr[i],arr[j]);
                    i++,j--;
                }
                else{
                    j--;
                }
                
            }
            else{
                if(arr[j]==0){
                    i++;
                }
                else{
                    i++,j--;
                }
            }
        }
    }
};

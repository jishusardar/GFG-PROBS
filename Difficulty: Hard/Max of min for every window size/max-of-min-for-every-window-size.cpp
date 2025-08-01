
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
    vector<int>ans(n,0);
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[i]<arr[st.top()]){
            int index=st.top();
            st.pop();
            if(st.empty()){
                int range=i;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            else{
                int range=i-st.top()-1;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
        }
        st.push(i);
    }
    while(!st.empty()){
        int index=st.top();
        st.pop();
        if(st.empty()){
            int range=n;
            ans[range-1]=max(ans[range-1],arr[index]);
        }
        else{
            int range=n-st.top()-1;
            ans[range-1]=max(ans[range-1],arr[index]);
        }
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1],ans[i]);
    }
    return ans;
    }
};
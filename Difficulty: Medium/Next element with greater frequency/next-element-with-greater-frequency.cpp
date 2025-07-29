class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        vector<int>ans(arr.size());
        stack<int>st;
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&freq[arr[st.top()]]<freq[arr[i]]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
    }
};

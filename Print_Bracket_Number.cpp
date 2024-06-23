vector<int> bracketNumbers(string str) {
        int n=str.size();
        vector<int>counts;
        stack<int>s;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')
            {
                count++;
                s.push(count);
                counts.push_back(count);
            }
            else if(str[i]==')')
            {
                int num=s.top();
                counts.push_back(num);
                s.pop();
            }
        }
        return counts;
    }
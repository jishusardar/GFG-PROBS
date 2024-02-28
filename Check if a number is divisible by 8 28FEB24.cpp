int DivisibleByEight(string s){
        int n=s.length();
        if(n<=3)
        {
            if(stoi(s)%8==0)
            return 1;
            else
            return -1;
        }
        else
        {
            string sub=s.substr(n-3);
            if(stoi(sub)%8==0)
            return 1;
            else
            return -1;
        }
        
    }

string compareFrac(string str) {
        double a,b,c,d;
        a=b=c=d=0;
        regex ex("([0-9]+)\\/([0-9]+), ([0-9]+)\\/([0-9]+)",regex_constants :: ECMAScript);
        smatch exp;
        if(regex_search(str,exp,ex))
        {
         a=stod(exp[1]),b=stod(exp[2]),c=stod(exp[3]),d=stod(exp[4]);
        }
        string ans="";
        if((a/b)==(c/d))
        return "equal";
        else if((a/b)>(c/d))
        {
            int a2=(int)a;
            int b2=(int)b;
            ans+=to_string(a2);
            ans+="/";
            ans+=to_string(b2);
        }
        else
        {
            int c2=(int)c;
            int d2=(int)d;
            ans+=to_string(c2);
            ans+="/";
            ans+=to_string(d2);
        }
        return ans;
    }

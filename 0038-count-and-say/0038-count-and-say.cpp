class Solution {
public:
    string countAndSay(int n) {
        string s="";
        if(n==1) { s+='1';return s;}
        for(int i=1;i<=n;i++){
            if(i==1) { 
                s="1" ;
                continue; 
            }
            if(i==2){
                s="11";
                continue;
            }
            int j=0,count=1;string k="";
            while(j<s.length()){
                if(s[j]==s[j+1]){
                    count++;
                }
                else{
                    string con;
                    con = to_string(count);
                    k+=con;
                    k+=s[j];
                    count=1; 
                }
                j++;
            }
            s=k;
        }
        return s;
    }
};



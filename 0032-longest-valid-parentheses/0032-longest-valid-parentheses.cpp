class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>str;
        str.push(-1);
        int maxlength=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                str.push(i);
            }else{
                str.pop();
                if(str.empty()){
                    str.push(i);
                }else{
                 maxlength=max(maxlength,i-str.top());
                }
            }
        }return maxlength;
    }
};
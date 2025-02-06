class Solution {
public:
    bool fun(int index1, int index2, string one, string two, vector<vector<int>>& dp){
        if(index1 == 0 && index2 == 0) return true;
        else if(index1 == 0 && index2 >= 1) return false;
        else if(index2 == 0 && index1 >= 1){
            for(int i = 0;i < index1;i++){
                if(one[i] != '*') return false;
            }
            return true;
        } 
        if(dp[index1][index2] != -1) return dp[index1][index2];       

        if(one[index1-1] == two[index2-1] || one[index1-1] == '?'){
            return dp[index1][index2] = fun(index1-1, index2-1, one, two, dp);
        }
        else if(one[index1-1] == '*'){
            return dp[index1][index2] = fun(index1-1, index2, one, two, dp) || 
            fun(index1, index2-1, one, two, dp);
        }
        return dp[index1][index2] = false;
    }

    bool isMatch(string one, string two) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        string three = one;
        one = two;
        two = three;
        int n = one.size();
        int m = two.size();
        // return fun(n, m, one, two, dp);
        // vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
        vector<bool>dp(m+1, false);
        vector<bool>curr(m+1, false);
        dp[0] = true;
        for(int i = 1;i <= m;i++){
            dp[i] = false;
        }
        // for(int i = 1;i <= n;i++){
        //     dp[i][0] = false;
        //     bool flag = true;
        //     for(int ii = 0;ii < i;ii++){
        //         if(one[ii] != '*'){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[i][0] = flag; 
        // }

        for(int i = 1;i <= n;i++){
            curr[0] = false;
            bool flag = true;
            for(int ii = 0;ii < i;ii++){
                if(one[ii] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag; 
            for(int j = 1;j <= m;j++){
                if(one[i-1] == two[j-1] || one[i-1] == '?'){
                    curr[j] = dp[j-1];
                }
                else if(one[i-1] == '*'){
                    curr[j] = dp[j] || curr[j-1];
                }
                else curr[j] = false;
            }
            dp = curr;
        }

        return dp[m];
    }
};
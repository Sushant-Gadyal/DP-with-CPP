class Solution {
public:
    vector<vector<int>> dp;
    int f(string &s1, string &s2 ,int i, int j){

        if(i>=s1.size()) return 0;
        
        if(j>=s2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + f(s1,s2,i+1,j+1);
        }
        else return dp[i][j] =  max(  f(s1,s2,i+1,j), f(s1,s2,i,j+1) );
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,0));
        // return f(text1,text2,0,0);
        // dp[i][j]=> tells from i to n-1 and j to m-1 what is ans for lcs
        // subsequence prblm will similar to this take or not take

        for(int i=text1.size()-1 ; i>=0 ; i--){
            for(int j=text2.size()-1 ; j>=0  ; j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max( dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
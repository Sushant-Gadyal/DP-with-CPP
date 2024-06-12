
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int f(int n, int k, int t){
        
        if(n==0 && t==0) return 1;
        
        if(n==0) return 0;

        if(dp[n][t]!=-1) return dp[n][t];

        int sm=0;
        for(int v=1 ; v<=k ; v++){
            if(t-v<0) break;
            sm = ( (sm%mod) + ( f(n-1,k,t-v)%mod) )%mod;
        }

        return dp[n][t] = sm%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35,vector<int> (1005,-1));
        return f(n,k,target);
    }
};
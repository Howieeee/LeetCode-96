class Solution {
public:
    /*
        n=0 , 1種 空樹
        n=1 , 1種
        n=2 , 2種
        n=3 , 當3為root left-subtree就成為 n=2時的情況
              3為root時 right-subtree沒有可能 所以 root = 3時 = 2*1
              當2為root時 left-subtree=1 , right-subtree=3  => 一種
              當1為root時 left-subtree無 , right-subtree  =2 => 2種
              
              dp[0]*dp[2] + dp[1] * dp[1] + dp[2] * dp[0]
    
    */
    int numTrees(int n) {
        if(n==1)
            return 1;
        
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i] += dp[j]* dp[i-j-1];
            }
        }
        
        //cout << dp[n-1];
        
        return dp.back();
    }
};

class Solution {
public:
    //SMSM on code
    int sol =0 ;
    int n,m;
    
    // dfs take TlE
    void dfs(vector<vector<int>>&arr, int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==1)
            return;
        if(i == n-1 && j== m-1){
            sol++;
            return;
        }
        dfs(arr,i,j+1);
        dfs(arr,i+1,j);
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n= obstacleGrid.size();
        m = obstacleGrid[0].size();
        vector<vector<int>>dp(n+5 , vector<int>(m+5));
        //dp
        dp[1][0]=1;
        for (int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!obstacleGrid[i-1][j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
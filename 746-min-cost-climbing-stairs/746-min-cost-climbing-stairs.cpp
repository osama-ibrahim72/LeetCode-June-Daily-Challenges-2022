class Solution {
public:
    int dp[1010];
    int solve (int n,int cur,vector<int>& cost ){
        if(cur>=n)
            return 0;
        if(dp[cur]!=-1)
            return dp[cur];
        
        int x= solve(n,cur+1,cost);
        int y= solve(n,cur+2,cost);
        
        return dp[cur] = cost[cur]+min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        int sol1 = solve(n,0,cost);
        int sol2 = solve(n,1,cost);
        return min(sol1,sol2);
    }
};
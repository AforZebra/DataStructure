// https://www.interviewbit.com/old/problems/increasing-path-in-matrix/

int Solution::solve(vector<vector<int> > &A) {
    if(!A.size())return -1;
    int n = A.size(),m = A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[n-1][m-1] = 1;
    if(m > 1)
        dp[n-1][m-2] = A[n-1][m-1] > A[n-1][m-2] ? dp[n-1][m-1] + 1 : 0;
    if(n > 1)
        dp[n-2][m-1] = A[n-1][m-1] > A[n-2][m-1] ? dp[n-1][m-1] + 1 : 0;
    for(int i = n-1;i >= 0;i--){
        for(int j = m-1;j >= 0;j--){
            if(i == n-2 && j == m-1 || i == n-1 && j == m-2)continue;
            if(i+1 < n && A[i+1][j] > A[i][j] && dp[i+1][j])
                dp[i][j] = dp[i+1][j] + 1;
            if(j+1 < m && A[i][j+1] > A[i][j] && dp[i][j+1] )
                dp[i][j] = max(dp[i][j+1] + 1, dp[i][j]);
        }
    }
    return dp[0][0] ? dp[0][0] : -1;
}

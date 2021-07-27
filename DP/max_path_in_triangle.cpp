// https://www.interviewbit.com/old/problems/maximum-path-in-triangle/

int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>>dp(A.size()+1,vector<int>(A.size()+1,0));
    int n = A.size();
    for(int i = n-1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            dp[i][j] = max(dp[i+1][j+1],dp[i+1][j])+A[i][j];
        }
    }
    return dp[0][0];
}

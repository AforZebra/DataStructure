// https://www.interviewbit.com/problems/longest-palindromic-subsequence/

int palindrome(int strt, int end, string A, vector<vector<int>>&dp){
    if(strt == end)return 1;
    if(dp[strt][end] != -1)return dp[strt][end];
    if(strt > end)return 0;
    if(A[strt] == A[end]){
        dp[strt][end] = 2+palindrome(strt+1,end-1,A,dp);
        return dp[strt][end];
    }
    dp[strt][end] = max(palindrome(strt+1,end,A,dp),palindrome(strt,end-1,A,dp));
    return dp[strt][end];
}

int Solution::solve(string A) {
    vector<vector<int>>dp(A.size(),vector<int>(A.size(),-1));
    return palindrome(0,A.size()-1,A,dp);
}

// bottom-up

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(),B.end());
    int n = A.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}


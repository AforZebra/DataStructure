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

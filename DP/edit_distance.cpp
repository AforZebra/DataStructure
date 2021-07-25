// https://www.interviewbit.com/old/problems/edit-distance/

int edit(int i, int j, string A, string B, vector<vector<int>>&dp){
    if(i == -1)return j+1;
    if(j == -1)return i+1;
    if(dp[i][j] != -1)return dp[i][j];
    if(A[i] == B[j]){
        dp[i][j] = edit(i-1,j-1, A,B,dp);
        return dp[i][j];
    }
    int insert = 1 + edit(i-1,j, A,B,dp);
    int del = 1 + edit(i,j-1, A,B,dp);
    int replace = 1 + edit(i-1,j-1, A,B,dp);
    dp[i][j] = min(insert, min(del, replace));
    return dp[i][j];
}

int Solution::minDistance(string A, string B) {
    vector<vector<int>>dp(A.size(),vector<int>(B.size(),-1));
    return edit(A.size()-1, B.size()-1,A,B,dp);
}



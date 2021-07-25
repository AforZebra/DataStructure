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


// Bottom up

int Solution::minDistance(string A, string B) {
    vector<vector<int>>dp(A.size()+1,vector<int>(B.size()+1,0));
    for(int i = 1;i <= A.size();i++)dp[i][0] = i;
    for(int j = 1;j <= B.size();j++)dp[0][j] = j;
    for(int i = 1;i <= A.size();i++){
        for(int j = 1;j <= B.size();j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }
    return dp[A.size()][B.size()];
}

// https://www.interviewbit.com/old/problems/maximum-size-square-sub-matrix/

int Solution::solve(vector<vector<int> > &A) {
    int ans = 0, n = A.size(), m = A[0].size();
    for(int i = 0;i < n;i++){
        ans = max(ans, A[i][0]);
    }
    for(int i = 0;i < m;i++){
        ans = max(ans, A[0][i]);
    }
    for(int i = 1;i < A.size();i++){
        for(int j = 1;j < A[0].size();j++){
            if(A[i][j]){
                A[i][j] = min(A[i-1][j-1],min(A[i][j-1],A[i-1][j])) + 1;
            }
            ans = max(A[i][j],ans);
        }
    }
    return ans*ans;
}

// https://www.interviewbit.com/old/problems/longest-common-subsequence/

int Solution::solve(string A, string B) {
    int a = A.size(),b = B.size(),idx;
    vector<vector<int>>v(2,vector<int>(b+1,0));
    for(int i =1;i <= a;i++){
        for(int j = 1;j <= b;j++){
            idx = i%2;
            if(A[i-1] == B[j-1])
                v[idx][j] = v[1-idx][j-1] + 1;
            else
                v[idx][j] = max(v[1-idx][j],v[idx][j-1]);
        }
    }
    return v[idx][b];
}

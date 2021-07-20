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

// recursion

int call(int i,int j,vector<vector<int>>&v,string A,string B){
    if(i < 0 || j < 0)return 0;
    if(v[i][j] != -1)return v[i][j];
    if(A[i] == B[j]){
        v[i][j] = 1 + call(i-1,j-1,v,A,B);
        return v[i][j];
    }
    v[i][j] = max(call(i-1,j,v,A,B),call(i,j-1,v,A,B));
    return v[i][j];
}

int Solution::solve(string A, string B) {
    int a = A.size(),b = B.size(),idx;
    vector<vector<int>>v(a,vector<int>(b,-1));
    call(a-1,b-1,v,A,B);
    return v[a-1][b-1];
}


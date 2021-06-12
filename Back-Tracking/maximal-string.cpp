// https://www.interviewbit.com/problems/maximal-string/

void findMx(string A, int B, int n, string &mx){
    if(mx < A)mx = A;
    if(B == 0)return;
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            if(A[j]>A[i]){
                swap(A[i], A[j]);
                findMx(A, B - 1, n, mx);
                swap(A[i], A[j]);
            }
        }
    }
}

string Solution::solve(string A, int B) {
    string mx = A;
    findMx(A, B, A.size(), mx);
    return mx;
}

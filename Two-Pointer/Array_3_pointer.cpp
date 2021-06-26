// https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int sizeA = A.size(), sizeB = B.size(), sizeC = C.size(), ans = INT_MAX;
    for(int i = 0, j = 0, k = 0; i < sizeA && j < sizeB && k < sizeC;){
        ans = min(ans, max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i]))));
        if(A[i] <= B[j] && A[i] <= C[k])i++;
        else if(B[j] <= A[i] && B[j] <= C[k])j++;
        else k++;
    }
    return ans;
}
